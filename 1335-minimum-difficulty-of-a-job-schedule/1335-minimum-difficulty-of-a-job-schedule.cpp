class Solution
{
public:
    int k = 1e5;
    int solve(vector<int> &jobDifficulty, int d, int i, vector<vector< int>> &dp)
    {
        if (d == 1)
        {
            int mx = 0;
            for (int j = i; j < jobDifficulty.size(); j++)
            {
                mx = max(mx, jobDifficulty[j]);
            }
            return mx;
        }

        if (i == jobDifficulty.size() || d == 0)
        {
            return k;
        }

        int &ans = dp[i][d];
        if (ans != -1)
        {
            return ans;
        }
        ans = k;
        d--;
        int mx = 0;
        for (int j = i; j < jobDifficulty.size() - d; j++)
        {
            mx = max(mx, jobDifficulty[j]);
            ans = min(ans, mx + solve(jobDifficulty, d, j + 1, dp));
        }
        return ans;
    }

    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        int n = jobDifficulty.size();
        vector<vector < int>> dp(n + 1, vector<int> (d + 1, -1));
        int ans = solve(jobDifficulty, d, 0, dp);
        return ans == k ? -1 : ans;
    }
};