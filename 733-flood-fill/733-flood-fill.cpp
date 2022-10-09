class Solution {
    int m, n;
    typedef vector<vector<int>> vvi;
    void dfs(vvi &image, vvi &vis, int i, int j, int color, int curr) {
        if (i < 0 || j < 0 || i >= m || j >= n || image[i][j] != curr
            || vis[i][j]) 
            return;
        
        image[i][j] = color;
        vis[i][j] = 1;
        dfs(image, vis, i-1, j, color, curr);
        dfs(image, vis, i+1, j, color, curr);
        dfs(image, vis, i, j-1, color, curr);
        dfs(image, vis, i, j+1, color, curr);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        
        vector<vector<int>> vis(m, vector<int> (n, 0));
        
        dfs(image, vis, sr, sc, color, image[sr][sc]);
        return image;
    }
};