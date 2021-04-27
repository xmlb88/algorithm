#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

// ����ָ����쳣

void f() {
    shared_ptr<int> sp(new int(42));    // ����һ���¶���
    // ��δ����׳�һ���쳣������f��δ������
}   // �ں�������ʱshared_ptr�Զ��ͷ��ڴ�

void f2() {
    int *ip = new int(42);  // ��̬����һ���¶���
    // ��δ����׳�һ���쳣������f��δ������
    delete ip;  // ���˳�֮ǰ�ͷ��ڴ�
}

// example:
struct destination; // ��ʾ������������ʲô
struct connection;  // ʹ�������������Ϣ
connection connect(destination*);   // ������
void disconnect(connection);    // �رո���������
void f3(destination &d /* �������� */ ) {
    // ���һ�����ӣ���סʹ�����Ҫ�ر���
    connection c = connect(&d);
    // ʹ������
    // ���������f�˳�ǰ���ǵ���disconnect,���޷��ر�c��
}

// �ȶ��庯������delete, ɾ����(deleter)����
void end_connection(connection *p) {
    disconnect(*p);
}

void f4(destination &d /* �������� */ ) {
    connection c = connect(&d);
    shared_ptr<connection> p(&c, end_connection);
    // ʹ�����ӣ�
    // ��f4�˳�ʱ����ʹ�����쳣���˳���connection�ᱻ��ȷ�ر�
}

// 416