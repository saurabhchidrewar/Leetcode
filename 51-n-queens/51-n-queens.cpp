class Solution
{
    bool check(vector<string> &board, int i, int j) {
        int a = i, b = j, n = board.size();
        while (a >= 0 && b >= 0) {
            if (board[a][b] == 'Q') return false;
            a--;
            b--;
        }
        
        a = i, b = j;
        while (a >= 0 && b >= 0) {
            if (board[a][b] == 'Q') return false;
            b--;
        }
        
        a = i, b = j;
        while (a < n && b >= 0) {
            if (board[a][b] == 'Q') return false;
            a++;
            b--;
        }
        
        return true;
    }
    
    void isValid(vector<vector < string>> &ans, int col, int n, vector<string> &chess)
    {
        if (col == n)
        {
            ans.push_back(chess);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (check(chess, row, col))
            {
                chess[row][col] = 'Q';
                isValid(ans, col + 1, n, chess);
                chess[row][col] = '.';
            }
        }
    }
    public:
        vector<vector < string>> solveNQueens(int n)
        {
            vector<vector < string>> ans;
            vector <string> chess;
            string s(n, '.');
            for (int i = 0; i < n; i++)
            {
                chess.push_back(s);
            }

            isValid(ans, 0, n, chess);

            return ans;
        }
};