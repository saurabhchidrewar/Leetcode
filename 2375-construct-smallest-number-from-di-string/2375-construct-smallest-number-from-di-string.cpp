class Solution {
public:
    string smallestNumber(string pattern) {
        stack <int> st;
        int count = 1, n = pattern.size();
        string arr;
        for (int i = 0; i <= n; i++) arr += 'Z';
        // cout << arr << endl;
        for (int i = 0; i <= n; i++) {
            if (pattern[i] == 'I') {
                arr[i] = (char)(count + '0');
                count++;
                while (!st.empty()) {
                    arr[st.top()] = (char)(count + '0');
                    count++;
                    st.pop();
                }
            } else st.push(i);
        }
        while (!st.empty()) {
            arr[st.top()] = (char)(count + '0');
            count++;
            st.pop();
        }
        return arr;
    }
};