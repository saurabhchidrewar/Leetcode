class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map <int,pair<int,int>> mp;
        for (int i = 0; i < matches.size(); i++) {
            mp[matches[i][0]].first++;
            mp[matches[i][1]].second++;
        }
        vector <int> ans1, ans2;
        for (auto &c: mp) {
            // cout << c.first << " : " << c.second.first << " " << c.second.second << endl;
            if (c.second.second == 0) ans1.push_back(c.first);
            if (c.second.second == 1) ans2.push_back(c.first);
        }
        
        sort(ans1.begin(), ans1.end());
        sort(ans2.begin(), ans2.end());
        
        vector <vector<int>> res;
        res.push_back(ans1);
        res.push_back(ans2);
        
        return res;
     }
};