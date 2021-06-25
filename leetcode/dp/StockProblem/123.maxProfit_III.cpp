#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    vector<vector<int>> buy(n, vector<int> (3)), sell(n, vector<int> (3));
    buy[0][0] = -prices[0], buy[0][1] = INT_MIN / 2, buy[0][2] = INT_MIN / 2;
    sell[0][0] = 0, sell[0][1] = INT_MIN / 2, sell[0][2] = INT_MIN / 2;
    for (int i = 1; i < n; i++) {
        buy[i][0] = max(buy[i - 1][0], sell[i - 1][0] - prices[i]);
        for (int j = 1; j <= 2; j++) {
            buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
            sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
        }
    }

    return *max_element(sell[n - 1].begin(), sell[n - 1].end());
}


// dp[i][k][0] ��i��������k�ν��״���δ���й�Ʊ������� dp[i][k][1] ��i��������k�ν��״������й�Ʊ�������
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (3, vector<int> (2)));

    // dp[i][0][0] = 0
}

/**
 * ������׽���ʱ��һ������5��״̬��

dp0��һֱ����
dp1�������Ҳֻ������һ��
dp2�����������һ�ʣ�����һ��
dp3��������������ʣ�����һ��
dp4��������������ʣ���������

��ʼ��5��״̬��

dp0 = 0
dp1 = - prices[0]
��Ϊ��һ�첻���ܻ���dp2��dp3��dp4����״̬����˽���������Ϊ������(Java����Ϊint���±߽�)
dp2 = float("-inf")
dp3 = float("-inf")
dp4 = float("-inf")

��5��״̬����״̬ת�ơ�

dp0 = 0
#һֱΪ0
dp1 = max(dp1, dp0 - prices[i])
#ǰһ��Ҳ��dp1״̬������ǰһ����dp0״̬����������һ�ʱ��dp1״̬
dp2 = max(dp2, dp1 + prices[i])
#ǰһ��Ҳ��dp2״̬������ǰһ����dp1״̬����������һ�ʱ��dp2״̬
dp3 = max(dp3, dp2 - prices[i])
#ǰһ��Ҳ��dp3״̬������ǰһ����dp2״̬����������һ�ʱ��dp3״̬
dp4 = max(dp4, dp3 + prices[i])
#ǰһ��Ҳ��dp4״̬������ǰһ����dp3״̬����������һ�ʱ��dp4״̬

���һ��������û�й�Ʊ׬��Ǯ��࣬����һ�����״���Խ��׬��Խ�࣬Ӧ��Ҫ����dp0��dp2��dp4�����ֵ�������Ҵ����д������ʵ������ͬһ�����������ģ�ֻ������Ϊһ��ļ۸񲻱������Խ����Ӱ�죬������ֵ�Ǳ�Ȼ��ת�Ƶ�dp4�ģ�����ֻҪ����dp4�Ϳ�����

*/

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n < 2) return 0;
    int dp_0 = 0, dp_1 = -prices[0], dp_2 = INT_MIN, dp_3 = INT_MIN, dp_4 = INT_MIN;

    for (int i = 1; i < n; ++i) {
        dp_1 = max(dp_1, dp_0 - prices[i]);
        dp_2 = max(dp_2, dp_1 + prices[i]);
        dp_3 = max(dp_3, dp_2 - prices[i]);
        dp_4 = max(dp_4, dp_3 + prices[i]);
    }

    return dp_4;
}