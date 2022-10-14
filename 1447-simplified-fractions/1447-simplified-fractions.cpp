class Solution {
    bool isCommon(int i, int j) {
        for (int k = 2; k <= min(i, j); k++) {
            if (i % k == 0 && j % k == 0) return true;
        }
        return false;
    }
public:
    vector<string> simplifiedFractions(int n) {
        vector <string> ans;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i >= j) continue;
                if (i != 1 && isCommon(i,j)) continue;
                ans.push_back(to_string(i) + "/" + to_string(j));
            }
        }
        
        return ans;
    }
};