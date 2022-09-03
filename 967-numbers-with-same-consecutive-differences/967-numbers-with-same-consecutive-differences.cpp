class Solution
{
    set<int> ans;
    void backtrack(int i, int n, int k, string temp)
    {
        if (temp.size() == n)
        {
            if (temp[0] == '0') return;
            int a = 0, m = 1;
            for (int i = n-1; i >= 0; i--) {
                a += (temp[i] - '0') * m;
                m *= 10;
            }
            ans.insert(a);
            return;
        }
        if (i + k <= 9)
            backtrack(i + k, n, k, temp + to_string(i + k));
        if (i - k >= 0)
            backtrack(i - k, n, k, temp + to_string(i - k));
    }
    public:
        vector<int> numsSameConsecDiff(int n, int k)
        {
            for (int i = 0; i <= 9; i++)
            {
                backtrack(i, n, k, "");
            }
            vector <int> res;
            for (auto c: ans) res.push_back(c);
            return res;
        }
};