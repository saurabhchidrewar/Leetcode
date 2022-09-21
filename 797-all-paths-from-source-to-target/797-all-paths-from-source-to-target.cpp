class Solution {
    void traverse(vector<vector<int>>& g, vector <vector<int>> &paths, vector <int> &path, int j) {
        path.push_back(j);
        if (j == g.size() - 1) {
            paths.push_back(path);
            return;
        }
        for (auto c: g[j]) {
            traverse(g, paths, path, c);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector <vector<int>> paths;
        vector <int> path;
        traverse(graph, paths, path, 0);
        return paths;
    }
};