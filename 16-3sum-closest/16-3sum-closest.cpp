class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0, n = nums.size(), diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int a = 0; a < n-2; a++) {
            int b = a+1, c = n-1;
            while (b < c) {
                int sm = nums[a] + nums[b] + nums[c];
                if (sm == target)
                    return sm;
                if (sm < target)
                    b++;
                else
                    c--;
                if (abs(sm - target) < diff) {
                    diff = abs(sm - target);
                    ans = sm;
                }
            }
        }
        return ans;
    }
};