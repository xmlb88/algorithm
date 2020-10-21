#include <iostream>
#include <set>
#include <queue>
#include <string>
using namespace std;

// int openLock(vector<string>deadends, string target) {

// }

// ������п��ܵ��������

// ��s[j]���ϲ���һ��
string plusOne(string s, int j) {
    string res = s;
    if (res[j] == '9') {
        res[j] = '0';
    } else res[j] += 1;

    return res;
}

// ��s[j]���²���һ��
string minusOne(string s, int j) {
    string res = s;
    if (res[j] == '0') {
        res[j] = '9';
    } else res[j] -= 1;

    return res;
}

// BFS��ܣ���ӡ���п��ܵ�����
int main(string target) {
    queue<string> q;
    q.push("0000");

    while (!q.empty()) {
        int sz = q.size();
        // ����ǰ�����е����нڵ�����Χ��ɢ
        for (int i = 0; i < sz; i++) {
            string cur = q.front();
            q.pop();
            // �������ж��Ƿ񵽴��յ�
            cout << cur << endl;

            // ��һ���ڵ�����ڽڵ�������
            for (int j = 0; j < 4; j++) {
                string up = plusOne(cur, j);
                string down = minusOne(cur, j);
                q.push(up);
                q.push(down);
            }
        }
        // ���������Ӳ���
    }
    return 0;
}


// ������ֹ������deadends��������visited
string plusOne(string s, int j) {
    string res = s;
    if (res[j] == '9') res[j] = '0';
    else res[j] += 1;

    return res;
}

string minusOne(string s, int j) {
    string res = s;
    if (res[j] == '0') res[j] = '9';
    else res[j] -= 1;

    return res;
}

int openLock(vector<string> deadends, string target) {
    // ��¼Ҫ��������������
    set<string> deads;
    for (string s : deadends) {
        deads.insert(s);
    }

    // ��¼�Ѿ���ٹ������룬��ֹ�߻�ͷ·
    set<string> visited;
    queue<string> q;

    // ����㿪ʼ���������������
    int step = 0;
    q.push("0000");
    visited.insert("0000");

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            string cur = q.front();
            q.pop();

            // �ж��Ƿ񵽴���������
            if (deads.find(cur) != deads.end()) {
                continue;
            }
            // �ж��Ƿ񵽴��յ�
            if (cur == target) {
                return step;
            }

            // ��һ���ڵ��δ�������ڽڵ�������
            for (int j = 0; j < 4; j++) {
                string up = plusOne(cur, j);
                if (visited.find(up) == visited.end()) {
                    q.push(up);
                    visited.insert(up);
                }

                string down = minusOne(cur, j);
                if (visited.find(down) == visited.end()) {
                    q.push(down);
                    visited.insert(down);
                }
            }
        }
        // ���������Ӳ���
        step++;
    }
    return -1;
}