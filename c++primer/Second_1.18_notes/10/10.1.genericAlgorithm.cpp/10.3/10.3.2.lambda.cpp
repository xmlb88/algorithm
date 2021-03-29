#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
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

// 351
// ���ò�������������ݣ�������һ���ַ���Ϊ�ָ�
void biggies(vector<string>& words, vector<string>::size_type sz, ostream& os = cout, char c = ' ') {
    // ��֮ǰ������һ������words�Ĵ���
    // ��ӡcount������Ϊ��ӡ��os
    for_each(words.begin(), words.end(), [&os, c] (const string& s){
        os << s << c;
    });
}

// ��ʽ����
// ��ʽֵ����
wc = find_if(words.begin(), words.end(), [=] (const string& s) {
    return s.size() >= sz;
});

// ���һ���ֲ���ֵ�������������������ò��񣬿��Ի��ʹ����ʽ�������ʾ����
void biggies(vector<string>& words, vector<string>::size_type sz, ostream& os = cout, char c = ' ') {
    // ����������֮ǰһ��
    // os��ʽ�������ò���ʽ��c��ʾ����ֵ����ʽ
    for_each(words.begin(), words.end(), [&, c] (const string& s) {
        os << s << c;
    });

    // os��ʾ�������ò���ʽ��c��ʽ����ֵ����ʽ
    for_each(words.begin(), words.end(), [=, &os] (const string& s) {
        os << s << c;
    });
}

// ������ʽ�������ʾ����ʱ�������б��е�һ��Ԫ�ر�����һ��&��=���˷���ָ����Ĭ�ϲ���ʽΪ���û�ֵ
// ����ʱ����ʾ����ı�������ʹ������ʽ����ͬ�ķ�ʽ


// �ɱ�lambda��
void fcn3() {
    size_t v1 = 42; // �ֲ�����
    // f���Ըı���������ı�����ֵ
    auto f = [v1] () mutable {return ++v1;};
    v1 = 0;
    auto j = f();   // j Ϊ43
}

// һ�����ò���ı����Ƿ�����޸������ڴ�����ָ�����һ��const���ͻ���һ����const����
void fcn4() {
    size_t v1 = 42; // �ֲ�����
    // v1��һ����const����������
    // ����ͨ��f2�е��������ı���
    auto f2 = [&v1] {return ++v1;};
    v1 = 0;
    auto j = f2(); // jΪ1
}

// ָ��lambda��������
// ���ӣ�ʹ�ñ�׼��transform�㷨��һ��lambda�������е�ÿ�������滻Ϊ�����ֵ
transform(vi.begin(), vi.end(), v1.begin(), [] (int i) {
    return i < 0 ? -i : i;
});

// ���󣺲����ƶ�lambda�ķ�������
transform(vi.begin(), vi.end(), vi.begin(), [] (int i) {
    if (i < 0) return -i;
    else return i;
});
// �������ƶ�����汾��lambda��������Ϊvoid������������һ��intֵ
// ����ҪΪһ��lambda���巵������ʱ������ʹ��β�÷�������
transform(vi.begin(), vi.end(), vi.begin(), [] (int i) -> int {
    if (i < 0) return -i;
    else return i;
});


// 10.3.4 ������

// ���ڲ���ֲ�������lambda���ú������滻��������ô����
// find_if����lambda���Ƚ�һ��string��һ��������С����д������
bool check_size(const string& s, string::size_type sz) {
    return s.size() >= sz;
}
// ���ǣ����ǲ��������������Ϊfind_if��һ��������find_if����һ��һԪν�ʣ�
// ���ݸ�find_if�Ŀɵ��ö��������ܵ�һ����
// ����������һԪν�ʣ���Ԫν��  


// �����check_size����һ�����Ȳ���������
// bind ͷ�ļ�#include <functional>
auto newCallable = bind(callable, arg_list);

auto check6 = bind(check_size, _1, 6);

auto wc = fidn_if(words.begin(), words.end(), [sz] (const string& a));
// ���滻Ϊ���°汾

auto wc = find_if(words.begin(), words.end(), bind(check_size, _1, sz));

// placeholders
using std::placeholders::_1;
using namespace std::placeholders;

// g��һ����2�������Ŀɵ��ö���
auto g = bind(f, a, b, _2, c, _1);

// ��bind���Ų�������
// �����ʳ����ɶ���������
sort(words.begin(), words.end(), isShorter);
// �����ʳ����ɳ���������
sort(words.begin(), words.end(), bind(isShorter, _2, _1));

// �����ò���
// ���磺�滻һ�����÷�ʽ����ostream��lambda��
// os��һ���ֲ�����������һ�������
// c��һ���ֲ�����������Ϊchar
for_each(words.begin(), words.end(), [&os, c] (const string& s) {
    os << s << c;
});

// ��д�����������ͬ�Ĺ���
ostream& print(ostream& os, const string& s, char c) {
    return os << s << c;
}

// ���ǣ�����ֱ����bind�����os�Ĳ���
// ���󣺲��ܿ���os
for_each(words.begin(), words.end(), bind(print, os, _1, ' '));

// ʹ��ref
for_each(words.begin(), words.end(), bind(print, ref(os), _1, ' '));
// ref����һ�����󣬰������������ã�cref����const ���õ���


