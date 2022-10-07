class Solution {
    int m,n;
    void traverse(vector<vector<int>>& rooms, vector<int>& vis, int i) {
        if (vis[i]) return;
        vis[i] = 1;
        for (auto c: rooms[i]) {
            traverse(rooms, vis, c);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        m = rooms.size();
        vector <int> vis(m, 0);
        traverse(rooms, vis, 0);
        for (int i = 0; i < m; i++) {
            if (vis[i] == 0) return false;
        }
        return true;
    }
};