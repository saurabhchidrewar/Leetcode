class Solution {
    int m, n;
    typedef vector<vector<int>> vvi;
    bool isValid(int i, int j) {
        return !(i < 0 || j < 0 || i >= m || j >= n);
    }
public:
    int orangesRotting(vvi& grid) {
        m = grid.size();
        n = grid[0].size();
        
        vvi vis(m, vector<int>(n, 0));
        
        int ans = 0;
        queue<pair<pair<int,int>, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
            }
        }
        
        while (!q.empty()) {
            int a = q.front().first.first;
            int b = q.front().first.second;
            int t = q.front().second;
            ans = max(ans, t);
            q.pop();
            
            if (isValid(a-1, b) && vis[a-1][b] == 0 && grid[a-1][b] != 0) {
                q.push({{a-1, b}, t+1});
                vis[a-1][b] = 2;
                grid[a-1][b] = 2;
            }
            if (isValid(a+1, b) && vis[a+1][b] == 0 && grid[a+1][b] != 0) {
                q.push({{a+1, b}, t+1});
                vis[a+1][b] = 2;
                grid[a+1][b] = 2;
            }
            if (isValid(a, b-1) && vis[a][b-1] == 0 && grid[a][b-1] != 0) {
                q.push({{a, b-1}, t+1});
                vis[a][b-1] = 2;
                grid[a][b-1] = 2;
            }
            if (isValid(a, b+1) && vis[a][b+1] == 0 && grid[a][b+1] != 0) {
                q.push({{a, b+1}, t+1});
                vis[a][b+1] = 2;
                grid[a][b+1] = 2;
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        
        return ans;
    }
};