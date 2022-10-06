class Solution {
    int m, n;
    
    typedef vector<vector<int>> vvi;
    
    void dfs(vvi &grid1, vvi &grid2, vvi &vis, int i, int j, bool &flag) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid2[i][j] != 1 || vis[i][j])
            return;
        
        vis[i][j] = 1;
        if (grid1[i][j] == 0) flag = false;
        
        dfs(grid1, grid2, vis, i-1, j, flag);
        dfs(grid1, grid2, vis, i+1, j, flag);
        dfs(grid1, grid2, vis, i, j-1, flag);
        dfs(grid1, grid2, vis, i, j+1, flag);
    }
    
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();
        
        int ans = 0;
        
        vector <vector<int>> vis(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1 && vis[i][j] == 0) {
                    bool flag = true;
                    dfs(grid1, grid2, vis, i, j, flag);
                    if (flag) {
                        // cout << i << " " << j << endl;
                        ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};