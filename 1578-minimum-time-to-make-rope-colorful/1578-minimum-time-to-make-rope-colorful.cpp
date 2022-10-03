class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size();
        int cost = 0, mx = INT_MIN, flag = false;
        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[i-1]) {
                if (!flag) {
                    cost += neededTime[i-1];
                    mx = max(mx, neededTime[i-1]);
                }
                cost += neededTime[i];
                mx = max(mx, neededTime[i]);
                flag = true;
            } else {
                if (flag)
                    cost -= mx;
                mx = INT_MIN;
                flag = false;
            }
            // cout << cost << " " << mx << endl;
        }
        if (flag) cost -= mx;
        return cost;
    }
};