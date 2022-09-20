class Solution
{
    public:
        vector<vector < int>> merge(vector<vector < int>> &intervals)
        {
            sort(intervals.begin(), intervals.end());

            vector<vector < int>> ans;

            for (auto &c: intervals)
            {
                int a = c[0], b = c[1];
                if (ans.size() == 0)
                {
                    ans.push_back({a, b});
                    continue;
                }

                int m = ans[ans.size() - 1][0], n = ans[ans.size() - 1][1];

                if (a >= m && a <= n)
                {
                    ans[ans.size() - 1][1] = max(b, n);
                }
                else
                {
                    ans.push_back({ a, b });
                }
            }

            return ans;
        }
};