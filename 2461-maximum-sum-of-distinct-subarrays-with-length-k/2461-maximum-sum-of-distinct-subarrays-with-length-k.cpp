class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map <int, int> mp;
        long long sm = 0, ans = 0;
        for (int i = 0; i < k; i++) {
            sm += nums[i];
            mp[nums[i]]++;
        }
        if (mp.size() == k) ans = sm;
        for (int i = k; i < nums.size(); i++) {
            mp[nums[i]]++;
            mp[nums[i-k]]--;
            
            if (mp[nums[i-k]] == 0) mp.erase(nums[i-k]);
            
            sm -= nums[i-k];
            sm += nums[i];
            
            if (mp.size() == k) ans = max(ans, sm);
        }
        return ans;
    }
};