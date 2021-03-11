#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // in   ����ʽ  (ifstream, fstream)
    // out  д��ʽ  (ofstream, fstream) 
    //(Ĭ��û��ָ��trunc���ļ�Ҳ��ضϣ������ļ�����ָ��app������ͬʱָ��inģʽ)
    // app  ÿ��д����ǰ����λ���ļ�ĩβ (truncû���趨�����Բ���ʾoutҲ��outģʽ��)
    // ate  ���ļ���������λ���ļ�ĩβ
    // trunc    �ض��ļ� (out)
    // binary   �Զ����Ʒ�ʽ����IO
    // ate �� binaryģʽ�������κ����͵��ļ��������ҿ����������κ��ļ�ģʽ���ʹ��

    // file1���ض�
    ofstream out("file1");  // ���������ģʽ���ļ����ض��ļ�
    ofstream out2("file1", ofstream::out);  // �����ض��ļ�
    ofstream out3("file1", ofstream::out | ofstream::trunc);

    // Ϊ�˱����ļ����ݣ�������ʾָ��appģʽ
    ofstream app("file2", ofstream::app); //�������ģʽ
    ofstream app2("file2", ofstream::out | ofstream::app);


    ofstream out;   // δָ���ļ���ģʽ
    out.open("scratchpad"); // ģʽģʽ����Ϊ����ͽض�
    out.close();
    out.open("precious", ofstream::app);    //���ģʽΪ׷��
    out.close();
}