//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        stack <char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (st.empty()) {
                st.push(s[i]);
            } else {
                if (s[i] == ']') {
                    string val;
                    while (st.top() != '[') {
                        val += st.top();
                        st.pop();
                    }
                    st.pop();
                    int k = 0, p = 1;
                    while (!st.empty() && (st.top() >= '0' && st.top() <= '9')) {
                        k += (st.top() - '0') * p;
                        p *= 10;
                        st.pop();
                    }
                    for (int i = 0; i < k; i++) {
                        for (int j = val.size()-1; ~j; j--) {
                            st.push(val[j]);
                        }
                    }
                } else st.push(s[i]);
            }
        }
        
        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends