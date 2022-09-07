class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 1)
            return triangle[0][0];
        int mn = INT_MAX;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0)
                    triangle[i][j] += triangle[i-1][j];
                else if (j == triangle[i].size() - 1)
                    triangle[i][j] += triangle[i-1][j-1];
                else
                    triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
                
                if (i == n-1) 
                    mn = min(mn, triangle[i][j]);
            }
        }
        return mn;
    }
};