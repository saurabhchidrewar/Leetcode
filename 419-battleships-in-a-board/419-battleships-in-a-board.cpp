class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') {
                    ans++;
                    int p = i, q = j;
                    if (p + 1 < m && board[p + 1][q] == 'X') {
                        while (p + 1 < m && board[p + 1][q] == 'X') {
                            p++;
                            board[p][q] = '.';
                        }
                    } else if (q + 1 < n && board[p][q+1] == 'X') {
                        while (q + 1 < n && board[p][q+1] == 'X') {
                            q++;
                            board[p][q] = '.';
                        }
                    }
                }
            }
        }
        return ans;
    }
};