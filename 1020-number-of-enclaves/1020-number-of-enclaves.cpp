class Solution {
    int m, n, cnt = 0; 
    bool flag = true;
    
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j] || !grid[i][j]) return;
        
        vis[i][j] = 1;
        cnt++;
        
        if (i == 0 || j == 0 || i == m-1 || j == n-1) flag = false;
        
        dfs(grid, vis, i-1, j);
        dfs(grid, vis, i+1, j);
        dfs(grid, vis, i, j-1);
        dfs(grid, vis, i, j+1);
    }
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        int ans = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    flag = true;
                    cnt = 0;
                    dfs(grid, vis, i, j);
                    if (flag) ans += cnt;
                }
            }
        }
        
        return ans;
    }
};