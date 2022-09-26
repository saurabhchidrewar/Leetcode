class Solution {
    bool backtrack(vector<int>& nums, int k, int target, int i, int curr,
                  vector <bool>& used) {
        if (k == 0)
            return true;
        if (curr == target)
            return backtrack(nums, k-1, target, 0, 0, used);
        
        for (int j = i; j < nums.size(); j++) {
            if (used[j] || curr + nums[j] > target)
                continue;
            used[j] = true;
            if (backtrack(nums, k, target, j+1, curr + nums[j], used))
                return true;
            used[j] = false;
        }
        return false;
    }
public:
    bool makesquare(vector<int>& nums) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s % 4 != 0)
            return false;
        int target = s/ 4, n = nums.size();
        vector <bool> used(n, false);
        sort(nums.rbegin(), nums.rend());
        return backtrack(nums, 4, target, 0, 0, used);
    }
};