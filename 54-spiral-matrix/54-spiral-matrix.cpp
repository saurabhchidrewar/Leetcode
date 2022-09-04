class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector <vector<int>> vis(m, vector<int>(n,-1));
        vector <int> ans;
        
        int i = 0, j = 0;
        char step = 'R';
        
        while (ans.size() < m*n) {
            if (vis[i][j] == -1) {
                vis[i][j] = 1;
                ans.push_back(matrix[i][j]);
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