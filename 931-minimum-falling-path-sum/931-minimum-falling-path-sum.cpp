class Solution
{
    bool isValid(int j, int n)
    {
        if (j < 0 || j >= n)
            return false;
        return true;
    }
    public:
        int minFallingPathSum(vector<vector < int>> &matrix)
        {
            int n = matrix.size(), mn = INT_MAX;
            if (n == 1)
                return* min_element(matrix[0].begin(), matrix[0].end());
            for (int i = 1; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int temp = matrix[i - 1][j];
                    if (isValid(j - 1, n))
                    {
                        temp = min(temp, matrix[i - 1][j - 1]);
                    }
                    if (isValid(j + 1, n))
                    {
                        temp = min(temp, matrix[i - 1][j + 1]);
                    }
                    matrix[i][j] += temp;

                    if (i == n - 1)
                        mn = min(mn, matrix[i][j]);
                }
            }
            return mn;
        }
};