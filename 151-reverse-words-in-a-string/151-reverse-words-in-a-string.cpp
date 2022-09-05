class Solution {
public:
    string reverseWords(string s) {
        string temp;
        vector <string> ans;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (temp == " ")
                    temp = "";
                if (temp.size()) {
                    ans.push_back(temp);
                    temp = "";
                }
            } else 
                temp += s[i];
        }
        if (temp.size())
            ans.push_back(temp);
        string res;
        for (auto c: ans) cout << c << endl;
        for (int i = ans.size()-1; i > 0; i--)
            res += (ans[i] + " ");
        res += ans[0];
        return res;
    }
};