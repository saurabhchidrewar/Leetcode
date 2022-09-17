class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0, n = popped.size();
        stack <int> st;
        while (j != n) {
            st.push(pushed[i++]);
            while (!st.empty() && popped[j] == st.top()) {
                st.pop();
                j++;
            }
            if (i == n && j != n) return false;
        }
        return true;
    }
};