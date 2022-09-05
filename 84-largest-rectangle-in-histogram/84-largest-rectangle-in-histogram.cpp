class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <int> st;
        int n = heights.size();
        int left[n], right[n];
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()]>=heights[i]) {
                st.pop();
            }
            if (st.empty()) left[i] = 0;
            else left[i] = st.top() + 1;
            st.push(i);
        }
        st = stack<int>();
        for (int i = n-1; ~i; i--) {
            while (!st.empty() && heights[st.top()]>=heights[i]) {
                st.pop();
            }
            if (st.empty()) right[i] = n-1;
            else right[i] = st.top()-1;
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            // cout << right[i] << " " << left[i] << endl;
            ans = max(ans, (right[i]-left[i]+1)*heights[i]);
        }
        return ans;
    }
};