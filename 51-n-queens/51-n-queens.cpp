class Solution
{
    int arr1[30] {}, arr2[30] {}, arr3[30] {};
    bool check(int row, int col, int n)
    {
        if ((arr1[row + col]) || (arr2[n - 1 + row - col]) || (arr3[row]))
            return false;
        return true;
    }

    void isValid(vector<vector < string>> &ans, int col, int n, vector< string > &chess)
    {
        if (col == n)
        {
            ans.push_back(chess);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (check(row, col, n))
            {
                chess[row][col] = 'Q';
                arr1[row + col] = 1;
                arr2[n - 1 + row - col] = 1;
                arr3[row] = 1;
                isValid(ans, col + 1, n, chess);
                chess[row][col] = '.';
                arr1[row + col] = 0;
                arr2[n - 1 + row - col] = 0;
                arr3[row] = 0;
            }
        }
    }
    public:
        vector<vector < string>> solveNQueens(int n)
        {
            vector<vector < string>> ans;
            vector<string> chess;
            string s(n, '.');
            for (int i = 0; i < n; i++)
            {
                chess.push_back(s);
            }

            isValid(ans, 0, n, chess);

            return ans;
        }
};