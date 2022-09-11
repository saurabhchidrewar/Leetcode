class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for (auto p : points) {
            unordered_map <int,int> mp;
            for (auto q: points) {
                int x = p[0] - q[0], y = p[1] - q[1];
                int val = x*x + y*y;
                if (mp.find(val) == mp.end()) mp[val] = 1;
                else mp[val]++;
            }
            for (auto c: mp) {
                ans += c.second*(c.second-1);
            }
        }
        return ans;
    }
};