class Solution {
    int m, n;
    typedef vector<vector<int>> vvi;
    void dfs(vvi &image, int i, int j, int color, int curr) {
        if (i < 0 || j < 0 || i >= m || j >= n || image[i][j] != curr
            || image[i][j] == color) 
            return;
        
        image[i][j] = color;
        dfs(image, i-1, j, color, curr);
        dfs(image, i+1, j, color, curr);
        dfs(image, i, j-1, color, curr);
        dfs(image, i, j+1, color, curr);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};