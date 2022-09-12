class Solution
{
    bool isValid(int i, int j, int m, int n)
    {
        if (i < 0 || j < 0 || i >= m || j >= n) return false;
        return true;
    }

    int livePeople(vector<vector < int>> &board, int i, int j)
    {
        int ans = 0;
        int m = board.size(), n = board[0].size();
        for (int a = -1; a <= 1; a++)
        {
            for (int b = -1; b <= 1; b++)
            {
                if (a == 0 && b == 0) continue;
                if (isValid(i + a, j + b, m, n) &&
                    (board[i + a][j + b] == 1 || board[i + a][j + b] == -1 || board[i + a][j + b] == -2)) ans++;
            }
        }
        return ans;
    }
    public:
        void gameOfLife(vector<vector < int>> &board)
        {
            int m = board.size(), n = board[0].size();
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int n = livePeople(board, i, j);
                    if (board[i][j] == 1 || board[i][j] == -1 || board[i][j] == -2)
                    {
                        if (n < 2) board[i][j] = -1;
                        if (n > 3) board[i][j] = -2;
                    }
                    else
                    {
                        if (n == 3) board[i][j] = -3;
                    }
                }
            }
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (board[i][j] == -1 || board[i][j] == -2) board[i][j] = 0;
                    else if (board[i][j] == -3) board[i][j] = 1;
                }
            }
        }
};