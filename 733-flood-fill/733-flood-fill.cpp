class Solution {
    int m, n;
    bool isValid(int i, int j, int m, int n) {
        return !(i < 0 || j < 0 || i >= m || j >= n);
    }
    
    void solve(vector<vector<int>>& image, int sr, int sc, int color, int val, vector <vector<int>> &vis) {
        image[sr][sc] = color;
        vis[sr][sc] = 1;
        
        if (isValid(sr-1, sc, m, n) && !vis[sr-1][sc] && image[sr-1][sc] == val) 
            solve(image, sr-1, sc, color, val, vis);
        
        if (isValid(sr+1, sc, m, n) && !vis[sr+1][sc] && image[sr+1][sc] == val) 
            solve(image, sr+1, sc, color, val, vis);
        
        if (isValid(sr, sc-1, m, n) && !vis[sr][sc-1] && image[sr][sc-1] == val) 
            solve(image, sr, sc-1, color, val, vis);
        
        if (isValid(sr, sc+1, m, n) && !vis[sr][sc+1] && image[sr][sc+1] == val) 
            solve(image, sr, sc+1, color, val, vis);
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        vector <vector<int>> vis(m, vector<int>(n, 0));
        solve(image, sr, sc, color, image[sr][sc], vis);
        return image;
    }
};