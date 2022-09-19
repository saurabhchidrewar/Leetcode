class Solution {
    int dp[31] = {0,1};
public:
    int fib(int n) {
        if (n == 0 || n == 1)
            return dp[n];
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};