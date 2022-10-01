// Recursive
/*
class Solution {
    unordered_map <int,int> dp;
    int solve(string s, int i) {
        if (dp.find(i) != dp.end())
            return dp[i];
        if (s[i] == '0') 
            return 0;
        int res = solve(s, i+1);
        if (i+1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i+1] < '7')))
            res += solve(s, i+2);
        return dp[i] = res;
    }
    
public:
    int numDecodings(string s) {
        dp[s.size()] = 1;      
        return solve(s, 0);
    }
};
*/

class Solution {
public:
    int numDecodings(string s) {
        unordered_map <int,int> dp;
        dp[s.size()] = 1;
        for (int i = s.size()-1; ~i; i--) {
            if (s[i] == '0')
                dp[i] = 0;
            else
                dp[i] = dp[i+1];
            
            if (i+1 < s.size() && 
                (s[i] == '1' || (s[i] == '2' && s[i+1] < '7')))
                dp[i] += dp[i+2];
        }
        return dp[0];
    }
};