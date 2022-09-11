/*
Intuition: 
TC: O(n^2)

Create a hashmap storing distance of all the points from a point p
(Traversing in points array)

Store the correspondings boomerangs in ans.
1. If there are 3 points with same distance :
   # of possible combinations = 3 * (3-1) = 6
2. If there are 2 points with same distance : (a: b,c)
   # of possible combinations = 2 * (2-1) = 2 (a,b,c) (a,c,b)
*/

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