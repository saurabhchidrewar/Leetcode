class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue <int> q;
        int call = 0, ind = 0, n = deck.size();
        vector <int> ans(n, 0);
        sort(deck.begin(), deck.end());
        for (int i = 0; i < n; i++) q.push(i);
        while (ind != n) {
            int t = q.front();
            if (call % 2 == 0) {
                ans[t] = deck[ind];
                ind++;
            } else q.push(t);
            q.pop();
            call++;
        }
        return ans;
    }
};