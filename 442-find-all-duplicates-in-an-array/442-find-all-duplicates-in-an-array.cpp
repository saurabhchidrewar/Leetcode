class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map <int, int> mp;
        vector <int> ans;
        for (auto &c: nums) mp[c]++;
        for (auto &c: mp) {
            if (c.second > 1)
                ans.push_back(c.first);
        }
        return ans;
    }
};