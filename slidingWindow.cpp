#include <iostream>
#include <string>
#include <map>
using namespace std;

void slidingWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;

    int left = 0, right = 0;
    int valid = 0;

    while (right < s.size()) {
        // c�ǽ����봰�ڵ��ַ�
        char c = s[right];
        // ���ƴ���
        right++;
        // ���д��������ݵ�һϵ�и���

        // ...

        /*** debug �����λ�� ***/
        printf("window: [%d, %d) \n", left, right);


        //�ж���ര���Ƿ�Ҫ����
        while (window needs shrink) {
            // d�ǽ��Ƴ����ڵ��ַ�
            char d = s[left];
            // ���ƴ���
            left++;
            // ���д��������ݵ�һϵ�и���

            // ...

        }
    }
}