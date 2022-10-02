// memoization

/*
class Solution {
    int mod = 1e9 + 7;
    int solve(int n, int k, int target, vector <vector<int>> &dp) {
        if (target < 0)
            return 0;
        if ((n == 0 || k == 0) && target == 0)
            return 1;
        if (n == 0 || k == 0)
            return 0;
        
        if (dp[n][target] != -1) 
            return dp[n][target];
        
        long ans = 0;
        for (int i = 1; i <= k; i++) {
            ans += solve(n-1, k, target-i, dp) % mod;
        }
        
        return dp[n][target] = ans % mod;    
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector <vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solve(n, k, target, dp);
    }
};
*/

// Bottom UP DP
class Solution {
    int mod = 1e9 + 7;
public:
    int numRollsToTarget(int n, int k, int target) {
        vector <vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                long ans = 0;
                for (int m = 1; m <= k; m++) {
                    if (j-m>=0)
                        ans += dp[i-1][j-m] % mod;
                    // ans += solve(n-1, k, target-i, dp) % mod;
                }
                dp[i][j] = ans % mod;
            }
        }
        return dp[n][target];
    }
};