class Solution {
    int m, n;
    
    bool isValid(int i, int j) {
        return !(i < 0 || i >= m || j < 0 || j >= n);
    }
    
    bool func(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j) {
        vis[i][j] = 1;
        
        if (i == 0 || j == 0 || i == m-1 || j == n-1) return false;
        
        bool a = true, b = true, c = true, d = true;
        if (isValid(i-1, j) && grid[i-1][j] == 0 && !vis[i-1][j]) {
            a = func(grid, vis, i-1, j);
        }
        
        if (isValid(i+1, j) && grid[i+1][j] == 0 && !vis[i+1][j]) {
            b = func(grid, vis, i+1, j);
        }
        
        if (isValid(i, j-1) && grid[i][j-1] == 0 && !vis[i][j-1]) {
            c = func(grid, vis, i, j-1);
        }
        
        if (isValid(i, j+1) && grid[i][j+1] == 0 && !vis[i][j+1]) {
            d = func(grid, vis, i, j+1);
        }
        
        return (a && b && c && d);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int ans = 0;
        
        vector <vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    if (func(grid, vis, i, j)) {
                        // cout << i << " " << j << endl;
                        ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};