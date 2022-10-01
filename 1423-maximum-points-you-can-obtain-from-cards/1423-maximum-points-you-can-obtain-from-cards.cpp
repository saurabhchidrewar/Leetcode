class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        if (n == 1) return cardPoints[0];
        int ans = 0, start = n - k, end = n - 1;
        for (int j = start; j < n; j++) ans += cardPoints[j];
        
        int curr = ans;
        while (end != k-1) {
            // cout << start << " " << end << " " << curr << endl;
            curr -= cardPoints[start];
            start = (start + 1) % n;
            end = (end + 1) % n;
            curr += cardPoints[end];
            ans = max(ans, curr);
        }
        
        return ans;
    }
};