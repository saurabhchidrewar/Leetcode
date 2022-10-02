class Solution {
    int mod = 1e9 + 7;
    int solve(int n, int k, int target, vector <vector<long>> &dp) {
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
        vector <vector<long>> dp(n+1, vector<long>(target+1, -1));
        return solve(n, k, target, dp);
    }
};