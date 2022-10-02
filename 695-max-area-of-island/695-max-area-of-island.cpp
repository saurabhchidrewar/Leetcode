class Solution {
    int m,n;
    
    bool isValid(int i, int j) {
        return !(i < 0 || i >= m || j < 0 || j >= n);
    }
    
    int solve(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j, int &cnt) 
    {
        vis[i][j] = 1;
        cnt++;
        
        if (isValid(i-1, j) && grid[i-1][j]==1 && !vis[i-1][j])
            solve(grid, vis, i-1, j, cnt);
        
        if (isValid(i+1, j) && grid[i+1][j]==1 && !vis[i+1][j])
            solve(grid, vis, i+1, j, cnt);
        
        if (isValid(i, j-1) && grid[i][j-1]==1 && !vis[i][j-1])
            solve(grid, vis, i, j-1, cnt);
        
        if (isValid(i, j+1) && grid[i][j+1]==1 && !vis[i][j+1])
            solve(grid, vis, i, j+1, cnt);
        
        return cnt;
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size(); 
        int mx = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int temp = 0;
                    mx = max(mx, solve(grid, vis, i, j, temp));
                }
            }
        }
        
        return mx;
    }
};