class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1, elem = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] - elem > k) {
                ans++;
                elem = nums[i];
            }
        }
        return ans;
    }
};