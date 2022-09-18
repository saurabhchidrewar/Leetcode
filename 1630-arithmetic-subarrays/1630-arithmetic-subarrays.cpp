class Solution {
    bool solve(vector <int> nums, int i, int j) {
        sort(nums.begin() + i, nums.begin() + j + 1);
        // cout << i << " " << j << " : ";
        // for (auto &c: nums) cout << c << " ";
        // cout << endl;
        int diff = nums[i+1] - nums[i];
        for (int k = i+1; k <= j; k++) {
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