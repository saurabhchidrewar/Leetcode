class Solution {
    typedef vector<vector<int>> vvi;
    typedef vector<vector<char>> vvc;
    int m, n;
    
    void dfs(vvc &grid, vvi &vis, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0' || vis[i][j]) 
            return;
        
        vis[i][j] = 1;
        
        dfs(grid, vis, i-1, j);
        dfs(grid, vis, i, j-1);
        dfs(grid, vis, i+1, j);
        dfs(grid, vis, i, j+1);
    }
    
public:
    int numIslands(vvc& grid) {
        m = grid.size();
        n = grid[0].size();
        
        vvi vis(m, vector<int> (n, 0));
        int ans = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    ans++;
                    dfs(grid, vis, i, j);
                }
            }
        }
        
        return ans;
    }
};