class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int a = n - 1, b = n - 2, c = n - 3;
        
        while (c >= 0) {
            if (nums[a] < nums[b] + nums[c]) 
                return nums[a] + nums[b] + nums[c];
            a--;
            b--;
            c--;
        }
        
        return 0;
    }
};