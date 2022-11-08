class Solution {
public:
    string makeGood(string s) {
        stack <char> st;
        int diff = 'a' - 'A';
        for (auto &c: s) {
            if (!st.empty() && abs(st.top() - c) == diff) {
                st.pop();
            } else {
                st.push(c);
            }
        }
        string ans;
        while (!st.empty()) {
            char ch = st.top();
            st.pop();
            ans = ch + ans;
        }
        return ans;
    }
};