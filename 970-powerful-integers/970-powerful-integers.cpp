class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector <int> xarr, yarr;
        int i = 1;
        while (i < bound) {
            xarr.push_back(i);
            i *= x;
            if (i == 1) break;
        }
        i = 1;
        while (i < bound) {
            yarr.push_back(i);
            i *= y;
            if (i == 1) break;
        }
        
        sort(xarr.begin(), xarr.end());
        sort(yarr.begin(), yarr.end());
        
        set <int> s;
        for (int i = 0; i < xarr.size(); i++) {
            for (int j = 0; j < yarr.size(); j++) {
                int temp = xarr[i] + yarr[j];
                if (temp <= bound)
                    s.insert(temp);
                else
                    break;
            }
        }
        
        vector <int> ans(s.begin(), s.end());
        return ans;
    }
};