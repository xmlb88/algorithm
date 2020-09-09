def coinChange(coins:List[int], amount:int):

    def dp(n):
        #base
        if n == 0: return 0
        if n < 0: return -1
        res = float('INF')
        for coin in coins:
            subproblem = dp(n - coin)
            if subproblem == -1: continue
            res = min(res, 1 + (subproblem))

        return res if res != float('INF') else -1

    return dp(amount)

def coinChange1(coins:List[int], amount:int):
    #备忘录
    memo = dict()
    def dp(n):
        # 查备忘录，避免重复计算
        if n in memo: return memo[n]
        # base
        if n == 0: return 0
        if n < 0: return -1
        res = flaot('INF')
        for coin in coins:
            subproblem = dp(n - coin)
            if subproblem == -1: continue
            res = min(res, 1 + subproblem)

        #记入备忘录
        memo[n] = res if res != float('INF') else -1
        return memo[n]

    return dp(amount)

