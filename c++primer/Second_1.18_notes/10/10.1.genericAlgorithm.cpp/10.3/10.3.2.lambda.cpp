#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void biggies(vector<string>& words, vector<string>::size_type sz) {
    elimsDups(words);   // ��words���ֵ�������ɾ���ظ�����
    // ���������򣬳�����ͬ�ĵ���ά���ֵ���
    stable_sort(words.begin(), words.end(), isShorter);
    // ��ȡһ����������ָ���һ������size() >= sz��Ԫ��
    // ��������size >= szԪ�ص���Ŀ
    // ��ӡ���ȴ��ڵ��ڸ���ֵ�ĵ��ʣ�ÿ�����ʺ����һ���ո�

}

// find_if()������һ�Ե���������ʾһ����Χ��������������һ��ν��
// find_if()�㷨�����������е�ÿ��Ԫ�ص��ø��������ν�ʣ����ص�һ��ʹν�ʷ��ط�0ֵ��Ԫ�أ����������������Ԫ�أ�����β�������


// lambda���ʽ���ɵ��õĴ��뵥Ԫ����⣺δ��������������
// ����һ���������ͣ�һ�������б��һ�������壬�뺯����ͬ��lambda���ܶ����ں����ڲ�
// [capture list] (parameter list) -> return type {function body}
// capture list(�����б�):��һ��lambda���ں����ж���ľֲ��������б�ͨ��Ϊ��
// ��������ͨ����һ��
// ����ͨ������ͬ���ǣ�lambda����ʹ��β�÷���
// �ɺ��Բ����б�ͷ������ͣ���������Զ���������б�ͺ�����
auto f = [] {return 42;};
// ����ͨ����һ��ʹ�õ��������()
cout << f() << endl;
// int main() {
//     cout << f() << endl;
// }

/* 
�������źͲ����б�ȼ���ָ��һ���ղ����б�
���Է������ͣ�lambda���ݺ������еĴ����ƶϳ��������ͣ�
���������ֻ��һ��return��䣬�򷵻����ʹӷ��صı��ʽ�������ƶ϶��������򷵻�����Ϊvoid
 */

// ��isShorter������ͬ��lambda
[] (const string& a, const string& b) {
    return a.size() < b.size();
}
/* 
�ղ����б���lambda��ʹ�������ں����е��κξֲ�����
 */

stable_sort(words.begin(), words.end(), [] (const string& a, const string& b)
{return a.size() < b.size();});


// ʹ�ò����б�
void biggies(vector<string>& words, vector<string>::size_type sz) {
    elimsDups(words);   // ��words���ֵ�������ɾ���ظ�����
    // ���������򣬳�����ͬ�ĵ���ά���ֵ���
    stable_sort(words.begin(), words.end(), isShorter);
    // ��ȡһ����������ָ���һ������size() >= sz��Ԫ��
    // ��������size >= szԪ�ص���Ŀ
    // ��ӡ���ȴ��ڵ��ڸ���ֵ�ĵ��ʣ�ÿ�����ʺ����һ���ո�

    [sz] (const string& a) {return a.size() >= sz;};
    // ����find_if
    auto wc = find_if(words.begin(), words.end(), [sz] (const string& a) {
        return a.size() >= sz;
    });

    // ��find_if���صĵ��������������ʼ��words��ĩβһ���ж��ٸ�Ԫ��
    auto count = words.end() - wc;

    // for_each��ӡ
    for_each(wc, words.end(), [] (const string& s){
        cout << s << " ";
    });
}

/* 
lambda����ͷ���
ֵ����
�봫ֵ�������ƣ�����ֵ�����ǰ���Ǳ������Կ���
�������ͬ��������ı�����ֵ����lambda����ʱ�����������ǵ���ʱ����
 */

void fcn1() {
    size_t v1 = 42; // �ֲ�����
    // ��v1��������Ϊf�Ŀɵ��ö���
    auto f = [v1] {return v1;};
    v1 = 0;
    auto j = f(); // jΪ42��f���������Ǵ�����ʱv1�Ŀ���
}

/* 
���ò���
 */

void fcn2() {
    size_t v1 = 42;
    auto f2 = [&v1] {return v1;};
    v1 = 0;
    auto j = f2(); // jΪ0��f2����v1������
}