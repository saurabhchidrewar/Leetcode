class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack <char> st;
        int counts[26]{}, vis[26]{};
        for (auto c: s) counts[c - 'a']++;
        for (auto c: s) {
            if (st.size() == 0) {
                st.push(c);
                vis[c - 'a']++;
                counts[c - 'a']--;
                continue;
            }
            
            while ((st.size()) && (c < st.top()) && (counts[st.top() - 'a'] > 0) && vis[c - 'a'] == 0) {
                vis[st.top() - 'a'] = 0;
                st.pop();
            }
            
            if (vis[c - 'a'] == 0) {
                st.push(c);
                vis[c - 'a']++;
            } 
            counts[c - 'a']--;
        }
        
        string ans;
        while (st.size()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};