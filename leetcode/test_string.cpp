#include<iostream>
#include<string>
using namespace std;

int main () {
    string s("1a2b3c4d5e6f7g8h9i1a2b3c4d5e6f7g8ha9i");
    string flag;
    string::size_type position;

    //find ���� ����jk ��s �е��±�λ�� 
    position = s.find("jk");
    if (position != s.npos)  //���û�ҵ�������һ���ر�ı�־c++����npos��ʾ��������nposȡֵ��4294967295��
    {
    cout << "position is : " << position << endl;
    }
    else
    {
    cout << "Not found the flag" + flag;
    } 


    //find ���� ����flag �������ַ� ��s �е�һ�γ��ֵ��±�λ��
    flag = "c";
    position = s.find_first_of(flag);
    cout << "s.find_first_of(flag) is : " << position << endl;

    //���ַ���s �±�5��ʼ�������ַ���b ,����b ��s �е��±�
    position=s.find("b",5);
    cout<<"s.find(b,5) is : "<<position<<endl;

    //����s ��flag ���ֵ�����λ�á�
    flag="a";
    position=0;
    int i=1;
    while((position=s.find_first_of(flag,position))!=string::npos)
    {
    //position=s.find_first_of(flag,position);
    cout<<"position  "<<i<<" : "<<position<<endl;
    position++;
    i++;
    }

    //����flag ����s ��һ����ƥ���λ��
    flag="acb12389efgxyz789";
    position=flag.find_first_not_of (s);
    cout<<"flag.find_first_not_of (s) :"<<position<<endl;


    //������ң�flag ��s �������ֵ�λ��
    flag="3";
    position=s.rfind (flag);
    cout<<"s.rfind (flag) :"<<position<<endl;
}