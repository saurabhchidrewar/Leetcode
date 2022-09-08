class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = INT_MIN, val = 0;
        for (auto &c : nums)
        {
            val += c;
            mx = max(mx, val);
            val = max(val, 0);
        }
        return mx;
    }
};