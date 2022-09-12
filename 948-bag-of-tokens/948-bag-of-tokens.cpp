class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0, i = 0, j = tokens.size()-1, ans = 0;
        sort(tokens.begin(), tokens.end());
        while (i <= j) {
            if (tokens[i] <= power) {
                power -= tokens[i];
                score++;
                i++;
            } else {
                if (score < 1) return 0;
                power += tokens[j];
                score--;
                j--;
            }
            ans = max(ans, score);
        }
        return ans;
    }
};