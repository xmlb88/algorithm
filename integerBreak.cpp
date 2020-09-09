

int integerBreak(int n) {
    vector<int> dp(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        int curMax = 0;
        for (int j = 1 ; j < i; j++) {
            curMax = max(curMax, max(j * (i - j), j * dp[i - j]));
        }
        dp[i] = curMax;
    }

    return dp[n];
}

/* 
����dp[i] : ��i���в�ֳ�j����ʱ�˻� = i * (i - j)�� i - j ���Լ�����֣�Ҳ���Բ���
״̬ת�ƣ�dp[i] = max(j * (i - j), j * dp[i - j])
base case : dp[0] = dp[1] = 1
 */