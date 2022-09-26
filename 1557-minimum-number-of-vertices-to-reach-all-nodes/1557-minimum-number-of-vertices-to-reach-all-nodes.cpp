/*
Count the nodes with indegree 0
If the node has indegree > 0, that means it can be reached via some node
Thus only consider nodes that cannot be traversed 
*/

class Solution
{
    public:
        vector<int> findSmallestSetOfVertices(int n, vector<vector < int>> &edges)
        {
            vector<int> ans, in (n, 0);
            for (auto c: edges)
                in[c[1]]++;
            for (int i = 0; i < n; i++)
                if (in[i] == 0)
                    ans.push_back(i);
            return ans;
        }
};