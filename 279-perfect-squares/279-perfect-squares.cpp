class Solution {
public:
    int numSquares(int n) {
        vector <int> arr;
        for (int i = 1; i <= pow(n, 0.5); i++)
            arr.push_back(i*i);
        int sz = arr.size()+1;
        int dp[sz][n+1];
        for (int i = 0; i < arr.size()+1; i++) {
            for (int j = 0; j < n+1; j++) {
                if (i == 0 || j == 0) 
                {
                    if (i == 0) 
                        dp[i][j] = INT_MAX - 1;
                    if (j == 0)
                        dp[i][j] = 0;
                }
                else
                {
                    if (arr[i-1] <= j)
                        dp[i][j] = min(1+dp[i][j-arr[i-1]],
                                      dp[i-1][j]);
                    else
                        dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[arr.size()][n];
    }
};