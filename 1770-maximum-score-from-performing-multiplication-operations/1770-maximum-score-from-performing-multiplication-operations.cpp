class Solution {
    int dp[1003][1003];
    int n,m;
    int maxScore(vector<int>& nums, vector<int>& multipliers, int i, int k) {
        if (k == m)
            return 0;

        if (dp[i][k] != (-1e9)) return dp[i][k];
        
        int val = multipliers[k];
        int a = (nums[i] * val) + maxScore(nums, multipliers, i+1, k+1);
        int b = (nums[n - (k - i) - 1] * val) + maxScore(nums, multipliers, i, k+1);
        
        return dp[i][k] = max(a, b);
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        n = nums.size();
        m = multipliers.size();
        for (int i = 0; i < 1003; i++) {
            for (int j = 0; j < 1003; j++) {
                dp[i][j] = -1e9;
            }
        }
        return maxScore(nums, multipliers, 0, 0);
    }
};