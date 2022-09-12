class Solution {
public:
    long long smallestNumber(long long num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        if (s[0] != '-') {
            int i = 0;
            while (s.size() > 1 && i < s.size() && s[i] == '0') i++;
            string temp = s;
            s = temp[i];
            for (int j = 0; j < temp.size(); j++) {
                if (j == i) continue;
                s += temp[j];
            }
        } else {
            reverse(s.begin()+1, s.end());
        }
        long long ans = 0;
        int power = 0;
        for (int i = s.size()-1; i >= 0; i--) {
            if (s[i] == '-') ans*=-1;
            else {
                ans += ((s[i] - '0') * pow(10, power));
                power++;
            }
        }
        return ans;
    }
};