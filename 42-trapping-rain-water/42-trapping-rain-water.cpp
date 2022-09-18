class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector <int> maxLeft(n,0), maxRight(n,0);
        int ml = height[0], mr = height[n-1];
        for (int i = 0; i < n; i++) {
            maxLeft[i] = max(ml, height[i]);
            maxRight[n-i-1] = max(mr, height[n-i-1]);
            ml = max(ml, maxLeft[i]);
            mr = max(mr, maxRight[n-i-1]);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(maxLeft[i], maxRight[i]) - height[i];
        }
        
        return ans;
    }
};