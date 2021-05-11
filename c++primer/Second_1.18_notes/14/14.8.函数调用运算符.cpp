#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// example
struct absInt {
    int operator() (int val) const {
        return val < 0 ? -val : val;
    }
};

// ʹ��
itnt i = -42;
absInt absObj;  // ���к�������������Ķ���
int ui = absObj(i); // ��i���ݸ�absObj.operator()

// �������� ��Ϊ����һ��


class PrintString {
public:
    PrintString(ostream &o = cout, char c = ' '):
        os(o), sep(c) {}
    void operator() (const string &s) const { os << s << sep; }
private:
    ostream &os;    // ����д���Ŀ����
    char sep;   // ���ڽ���ͬ����������ַ�
};

PrintString printer;    // ʹ��Ĭ��ֵ����ӡ��cout
printer(s); // ��cout�д�ӡs�� �����һ���ո�
PrintString errors(cerr, '\n');
errors(s);  // ��cerr�д�ӡs�������һ�����з�

// �������󳣳���Ϊ�����㷨��ʵ�Σ����磺
for_each(vs.begin(), vs.end(), PrintString(cerr, '\n'));

// *lambda�Ǻ�������
stable_sort(words.begin(), words.end(), 
    [](const string &a, const string &b)
    { return a.size() < b.size(); });

// ����Ϊ����������������һ��δ��������
class ShorterString {
public:
    bool operator() (const string &s1, const string &s2) cosnt {
        return s1.size() < s2.size();
    }
};

// ��д�����µ���stable_sort
stable_sort(words.begin(), words.end(), ShorterString());


// ��ʾlambda����Ӧ������Ϊ����
auto wc = find_if(words.begin(), words.end(), [sz] (cosnt string &s) {
    return a.size() >= sz;
});

// ��lambda���ʽ�������ཫ���磺
class SizeComp {
    SizeComp(size_t n) : sz(n) {}   // ���βζ�Ӧ����ı���
    // �õ���������ķ������͡��βκͺ����嶼��lambdaһ��
    bool operator() (const string &s) const {
        return s.size() >= sz;
    }
private:
    size_t sz;  // �����ݳ�Ա��Ӧͨ��ֵ����ı���
};

// ʹ�����������ṩһ��ʵ��
auto wc = find_if(words.begin(), words.end(), SizeComp(sz));




// ��׼�ⶨ��ĺ�������
plus<int> intAdd;   // ��ִ��int�ӷ��ĺ�����
negate<int> intNegate;  // �ɶ�intֵȡ���ĺ�������
// ʹ��intAdd::operator(int, int)��10��20�ĺ�
int sum = intAdd(10, 20);
sum = intNegate(intAdd(10, 20));

sum = intAdd(10, intNegate(10));

// ���㷨��ʹ�ñ�׼�⺯������
sort(svec.begin(), svec.end(), greater<string>());

// ����ָ��
vector<string*> nameTable;  // ָ���vector
// ����nameTable�е�ָ��˴�֮��û�й�ϵ������<������δ�������Ϊ
sort(nameTable.beign(), nameTable.end(), [] (string *a, string *b) {
    return a < b;
});
// ��ȷ����׼��涨ָ���less�Ƕ������õ�
sort(nameTable.begin(), nameTable.end(), less<string*>());


// �ɵ��ö�����function
// c++�м��ֿɵ��õĶ���
// ����������ָ�롢lambda���ʽ��bind�����Ķ����Լ������˺����������������
// 511