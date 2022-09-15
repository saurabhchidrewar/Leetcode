class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 == 1) return {};
        vector <int> ans;
        unordered_map <int,int> mp;
        sort(changed.begin(), changed.end());
        for (int i  = 0; i < n; i++) {
            if (mp.find(changed[i]) != mp.end() && mp[changed[i]] > 0) 
                mp[changed[i]]--;
            else {
                ans.push_back(changed[i]);
                mp[changed[i] * 2]++;
            }
        }
        for (auto c: mp) if (c.second > 0) return {};
        return ans;
    }
};