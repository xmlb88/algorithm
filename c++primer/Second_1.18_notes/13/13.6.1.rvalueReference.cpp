#include <iostream>
#include <vector>
#include <string>
using namespace std;

int i = 42;
int &r = i; // ��ȷ��r����i
int &&rr = i;   // ���󣺲��ܽ�һ����ֵ���ð󶨵�һ����ֵ��
int &r2 = i * 42;   // ����i * 42��һ����ֵ
const int &r3 = i * 42; // ��ȷ����һ��const�����ð󶨵�һ����ֵ��
int &&rr2 = i * 42; // ��ȷ����rr2�󶨵��˷������


int &&rr1 = 42;     // ��ȷ�����泣������ֵ
int &&rr2 = rr1;    // ���󣺱��ʽrr1����ֵ
#include <utility> // move
int &&rr3 = std::move(rr1); // ok
// ʹ��moveֱ����std::move

// 474