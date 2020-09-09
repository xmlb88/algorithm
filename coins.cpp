// dp�������
int coinChange(vector<int>& coins, int amount) {
    // �����СΪamount + 1����ʼֵҲΪamount + 1
    vector<int> dp(amount + 1, amount + 1);
    // base case
    dp[0] = 0;
    // ���forѭ����������״̬ȡֵ
    for (int i = 0; i < dp.size(); i++) {
        // �ڲ�forѭ��������ѡ����Сֵ
        for (coin in coins) {
            // �������޽⣬����
            if (i - coin < 0) continue;
            dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
    }
    return (dp[amount] == amount + 1)? -1 : dp[amount];
}