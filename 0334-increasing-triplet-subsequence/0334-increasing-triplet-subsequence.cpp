class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size(), mn = nums[0];
        int mx = nums[n-1];
        vector <int> small(n, 0), large(n, 0);
        
        for (int i = 0; i < nums.size(); i++) {
            small[i] = min(mn, nums[i]);
            mn = min(mn, nums[i]);
            
            large[n-i-1] = max(mx, nums[n-i-1]);
            mx = max(mx, nums[n-i-1]);
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > small[i] && nums[i] < large[i]) return true;
        }
        
        return false;
    }
};