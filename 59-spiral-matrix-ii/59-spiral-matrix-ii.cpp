class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector <vector<int>> vis(n, vector<int>(n,-1));
        vector <vector<int>> ans(n, vector<int>(n,-1));
        int m = n;
        int i = 0, j = 0;
        char step = 'R';
        int val = 1;
        
        while (val <= n*n) {
            if (vis[i][j] == -1) {
                vis[i][j] = 1;
                ans[i][j] = val;
                val++;
            }
            
            if (step == 'R') {
                if ((j == n-1) || (j+1 < n && vis[i][j+1] == 1))
                    step = 'D';
                else
                    j++;
            }
            
            if (step == 'D') {
                if ((i == m-1) || (i+1 < m && vis[i+1][j] == 1))
                    step = 'L';
                else
                    i++;
            }
            
            if (step == 'L') {
                if ((j == 0) || (j > 0 && vis[i][j-1] == 1))
                    step = 'U';
                else
                    j--;
            }
            
            if (step == 'U') {
                if (i > 0 && vis[i-1][j] == 1)
                    step = 'R';
                else
                    i--;
            }
        }
        
        return ans;
    }
};