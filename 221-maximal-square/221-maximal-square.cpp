class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int mx = 0;
        int m = matrix.size(), n = matrix[0].size();
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) dp[i][j] = matrix[i][j] - '0';
                else {
                    if (matrix[i][j] == '0') dp[i][j] = 0;
                    else {
                        dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    }
                }
                mx = max(mx, dp[i][j]);
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }
        return mx*mx;
    }
};