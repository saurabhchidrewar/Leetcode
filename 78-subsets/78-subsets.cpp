class Solution
{
    public:
        void func(vector<int> &arr, int i, int n, set<vector< int >> &ans, vector< int > temp)
        {
            if (i == n)
            {
                ans.insert(temp);
                return;
            }

            temp.push_back(arr[i]);
            func(arr, i + 1, n, ans, temp);

            temp.pop_back();
            func(arr, i + 1, n, ans, temp);
        }

    vector<vector < int>> subsets(vector<int> &nums)
    {
        vector<vector < int>> ans;
        set<vector < int>> a;
        vector<int> temp;

        sort(nums.begin(), nums.end());

        func(nums, 0, nums.size(), a, temp);

        for (auto c: a)
            ans.push_back(c);

        return ans;
    }
};