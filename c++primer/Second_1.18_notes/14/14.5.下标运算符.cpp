#include <iostream>
#include <vector>
#include <string>
using namespace std;

// �±�����������ǳ�Ա����
// example
class StrVec {
public:
    std::string& operator[](std::size_t n) {
        return elements[n];
    }
    const std::string& operator[](std::size_t n) const {
        return elements[n];
    }
private:
    std::string *elements;  // ָ��������Ԫ�ص�ָ��
}

// ����svec��һ��StrVec����
const StrVec cvec = svec;   // ��svec��Ԫ�ؿ�����cvec��
// ���svec�к���Ԫ�أ��Ե�һ��Ԫ������string��empty����
if (svec.size() && svec[0].empty()) {
    svec[0] = "zero";   // ��ȷ���±����������string������
    cvec[0] = "zip";    // ���󣺶�cvecȡ�±귵�ص��ǳ�������
}

