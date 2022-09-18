class Solution {
    bool solve(vector <int> &arr, int i, int j) {
        vector <int> nums;
        for (int k = i; k <= j; k++) nums.push_back(arr[k]);
        sort(nums.begin(), nums.end());
        int diff = nums[1] - nums[0];
        for (int k = 1; k < nums.size(); k++) {
            if (nums[k] - nums[k-1] != diff) return false;
        }
        return true;
    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector <bool> ans;
        for (int i = 0; i < l.size(); i++) {
            ans.push_back(solve(nums, l[i], r[i]));
        }
        return ans;
    }
};