#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public boolean isNumber(String s) {
        if(s == null || s.length() == 0) return false; // sΪ�ն���� s����Ϊ0(���ַ���)ʱ, ���ܱ�ʾ��ֵ
        boolean isNum = false, isDot = false, ise_or_E = false; // ����Ƿ�������λ��С���㡢��e����'E'
        char[] str = s.trim().toCharArray();  // ɾ���ַ���ͷβ�Ŀո�תΪ�ַ����飬��������ж�ÿ���ַ�
        for(int i=0; i<str.length; i++) {
            if(str[i] >= '0' && str[i] <= '9') isNum = true; // �жϵ�ǰ�ַ��Ƿ�Ϊ 0~9 ����λ
            else if(str[i] == '.') { // ����С����
                if(isDot || ise_or_E) return false; // С����֮ǰ����û�����������ǲ����ظ�����С���㡢����֡�e����'E'
                isDot = true; // ����Ѿ�����С����
            }
            else if(str[i] == 'e' || str[i] == 'E') { // ������e����'E'
                if(!isNum || ise_or_E) return false; // ��e����'E'ǰ���������������ǰ�治���ظ����֡�e����'E'
                ise_or_E = true; // ����Ѿ�������e����'E'
                isNum = false; // ����isNum����Ϊ��e����'E'֮��Ҳ���������������ֹ���� 123e����123e+�ķǷ����
            }
            else if(str[i] == '-' ||str[i] == '+') { 
                if(i!=0 && str[i-1] != 'e' && str[i-1] != 'E') return false; // ������ֻ���ܳ����ڵ�һ��λ�ã����߳����ڡ�e����'E'�ĺ���һ��λ��
            }
            else return false; // ���������Ϊ���Ϸ��ַ�
        }
        return isNum;
    }
}

bool isNumber (string s) {
    int n = s.size();
    int index = 0;
    bool hasDot = false, hasE = false, hasOp = false, hasNum = false;
    while (index < n && s[index] == ' ') index++;
    while (index < n) {
        if ('0' <= s[index] && s[index] <= '9') {
            hasNum = true;
        } else if (s[index] == 'e' || s[index] == 'E') {
            if (hasE || !hasNum) return false;
            hasE = true;
            hasOp = false;
            hasDot = false;
            hasNum = false;
        } else if (s[index] == '+' || s[index] == '-') {
            if (hasOp || hasNum || hasDot) return false;
            hasOp = true;
        } else if (s[index] == '.') {
            if (hasDot || hasE) return false;
            hasDot = true;
        } else if (s[index] == ' ') {
            break;
        } else return false;
        index++;
    }

    while (index < n && s[index] == ' ') index++;
    return hasNum && index == n;
}