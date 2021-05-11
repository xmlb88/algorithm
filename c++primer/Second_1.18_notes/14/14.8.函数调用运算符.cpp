#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <functional>
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

// ��ͬ���Ϳ��ܾ�����ͬ�ĵ�����ʽ
// ��ͨ����
int add(int i, int j) { return i + j; }
// lambda ����һ��δ�����ĺ���������
auto mod = [] (int i, int j) { return i % j; };
// ����������
struct divide {
    int operator() (int denominator, int divisor) {
        return denominator / divisor;
    }
};

// ͬһ����ʽ��
int (int, int)

// ������(function table)
// �����������������ָ���ӳ���ϵ�����к�������2��int������һ��int
map<string, int(*)(int, int)> binops;

// ��ȷ��add��һ��ָ����ȷ�������͵�ָ��
binops.insert({"+", add});
// �����ǲ��ܽ�mod����divide����binops
binops.insert({"%", mod});  // ����mod����һ������ָ��

// ��׼��function����

function<int(int, int)> f1 = add;   // ����ָ��
function<int(int, int)> f2 = divide();  // ����������Ķ���
function<int(int, int)> f3 = [] (int i, int j) { return i * j; }; // lambda
cout << f1(4, 2) << endl;
cout << f2(4, 2) << endl;
cout << f3(4, 2) << endl;

// ���¶���map
map<string, function<int(int, int)>> binops;
map<string, function<int(int, int)>> binops = {
    {"+", add},     // ����ָ��
    {"-", std::minus<int>()},   // ��׼�⺯������
    {"/", divide()},    // �û�����ĺ�������
    {"*", [] (int i, int j) { return i * j; }},     //δ������lambda
    {"%", mod}  // �����˵�lambda
};

binops["+"](10, 5); // ����add(10, 5)
binops["-"](10, 5); // ʹ��minus<int>����ĵ��������
binops["/"](10, 5); // ʹ��divide����ĵ��������
binops["*"](10, 5); // ����lambda��������
binops["%"](10, 5); // ����lambda��������


// ���ܣ�ֱ�ӣ������غ��������ִ���function���͵Ķ�����
int add(int i, int j) { return i + j; }
Sales_data add(const Sales_data&, const Sales_data&);
map<string, function<int(int, int)>> binops;
binops.insert({"+", add});  // �����ĸ�add��

// �������������һ��;���Ǵ洢����ָ�룬���Ǻ���������
int (*fp)(int, int) = add;  // ָ����ָ��add�ǽ���2��int�İ汾
binops.insert({"+", fp});   // ��ȷ��fpָ��һ����ȷ��add�汾

// ͬ����Ҳ��ʹ��lambda������������
// ��ȷ��ʹ��lambda��ָ������ϣ��ʹ�õ�add�汾
binops.insert("+", [] (int a, int b) { return add(a, b); });

