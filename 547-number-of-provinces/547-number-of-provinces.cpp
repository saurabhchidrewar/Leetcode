class Solution {
    int n;
    void dfs(vector<vector<int>>&grid, vector<int>& vis, int i) {
        vis[i] = 1;
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && vis[j] == 0)
                dfs(grid, vis, j);
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& grid) {
        n = grid.size();
        int ans = 0;
        vector <int> vis(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                dfs(grid, vis, i);
                ans++;
            }
        }
        
        return ans;
    }
};