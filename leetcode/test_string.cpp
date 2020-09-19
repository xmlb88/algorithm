#include<iostream>
#include<string>
using namespace std;

int main () {
    string s("1a2b3c4d5e6f7g8h9i1a2b3c4d5e6f7g8ha9i");
    string flag;
    string::size_type position;

    //find 函数 返回jk 在s 中的下标位置 
    position = s.find("jk");
    if (position != s.npos)  //如果没找到，返回一个特别的标志c++中用npos表示，我这里npos取值是4294967295，
    {
    cout << "position is : " << position << endl;
    }
    else
    {
    cout << "Not found the flag" + flag;
    } 


    //find 函数 返回flag 中任意字符 在s 中第一次出现的下标位置
    flag = "c";
    position = s.find_first_of(flag);
    cout << "s.find_first_of(flag) is : " << position << endl;

    //从字符串s 下标5开始，查找字符串b ,返回b 在s 中的下标
    position=s.find("b",5);
    cout<<"s.find(b,5) is : "<<position<<endl;

    //查找s 中flag 出现的所有位置。
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

    //查找flag 中与s 第一个不匹配的位置
    flag="acb12389efgxyz789";
    position=flag.find_first_not_of (s);
    cout<<"flag.find_first_not_of (s) :"<<position<<endl;


    //反向查找，flag 在s 中最后出现的位置
    flag="3";
    position=s.rfind (flag);
    cout<<"s.rfind (flag) :"<<position<<endl;
}