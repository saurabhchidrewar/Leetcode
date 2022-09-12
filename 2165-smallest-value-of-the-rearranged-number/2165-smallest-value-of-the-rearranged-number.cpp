class Solution {
public:
    long long smallestNumber(long long num) {
        string s = to_string(abs(num));
        sort(s.begin(), s.end());
        if (num <= 0) {
            reverse(s.begin(), s.end());
            return -1 * stoll(string(s.begin(), s.end()));
        } else {
            int i = 0;
            while (s[i] == '0') i++;
            swap(s[0], s[i]);
        }
        return stoll(s);
    }
};