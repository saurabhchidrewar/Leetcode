class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int es = 0;
        
        for (auto &c : nums) {
            if (c % 2 == 0) es += c;
        }
        
        vector <int> ans;
        
        for (auto &c : queries) {
            int i = c[1], v = c[0], latest = nums[i] + c[0];
            
            if (nums[i] % 2 == 0) {
                if (abs(latest) % 2 == 0) es += v;
                else es -= nums[i];
            } else if (abs(latest % 2) == 0) es += (nums[i] + v);
            nums[i] = latest;
            ans.push_back(es);
        }
        return ans;
    }
};