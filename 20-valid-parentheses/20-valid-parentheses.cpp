class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for (auto c: s) {
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else {
                if ((c == ')') && (st.size() == 0 || st.top() != '('))
                    return false;
                else if (c == ']' && (st.size() == 0 || st.top() != '[')) 
                    return false;
                else if (c == '}' && (st.size() == 0 || st.top() != '{')) 
                    return false;
                st.pop();
            }
        }
        if (st.size() > 0) return false;
        return true;
    }
};