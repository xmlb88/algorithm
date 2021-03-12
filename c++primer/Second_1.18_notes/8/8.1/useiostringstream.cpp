#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

// �ȶ���һ������������������
struct PersonInfo {
    string name;
    vector<string> phones;
};

int main(int argc, char **argv) {
    string file_name = argv[1];
    ifstream ifs(file_name);
    string line, word;  // ���������һ�к͵���
    vector<PersonInfo> people;  // ����������������м�¼
    // ���д������ȡ���ݣ�ֱ��cin�����ļ�ĩβ(����������)
    while (getline(ifs, line)) {
        PersonInfo info;    //����һ������μ�¼���ݵĶ���
        istringstream record(line); //����¼�󶨵��ն������
        record >> info.name;    // ��ȡ����
        while (record >> word) {    // ��ȡ�绰����
            info.phones.push_back(word);    // ��������
        }
        people.push_back(info); // ���˼�¼׷�ӵ�peopleĩβ
    }

    // use ostringstream

    ofstream os, oerr;
    os.open("rPhone", ofstream::app);
    oerr.open("bPhone", ofstream::app);
    
    for (const auto& entry : people) {  //��people�е�ÿһ��
        ostringstream formatted, badNums;   // ÿ��ѭ���������Ķ���
        for (const auto& nums : entry.phones) {
            if (nums.size() != 10) {
                badNums << " " << nums; // �������ַ�����ʽ����badNums
            } else {
                formatted << " " << nums;
            }
        }

        if (badNums.str().empty()) { // û�д������
            os << entry.name << " " 
               << formatted.str() << endl;
        } else {
            oerr << "input error: " << entry.name 
                 << " invalid numbers(s) " << badNums.str() << endl;
        }
    }
}