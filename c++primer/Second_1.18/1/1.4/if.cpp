#include <iostream>
int main() {
    // currVal����������ͳ�Ƶ��������ǽ��������ֵ����val
    int currVal = 0, val = 0;
    // ��ȡ��һ��������ȷ��ȷʵ�����ݿ��Դ���
    if (std::cin >> currVal) {
        int cnt = 1;
        while (std::cin >> val) {
            if (val == currVal)
                ++cnt;
            else {
                std::cout << currVal << " occurs "
                          << cnt << " times" << std::endl;
                currVal = val;
                cnt = 1;
            }
        }
        std::cout << currVal << " occurs "
                  << cnt << " times" << std::endl;
    }
    return 0;
}