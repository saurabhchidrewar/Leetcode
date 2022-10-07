class Solution {
    void traverse(vector<vector<int>>& rooms, vector<int>& vis, int &s, int i) {
        vis[i] = 1;
        s -= i;
        for (auto c: rooms[i]) {
            if (vis[c] == 0)
                traverse(rooms, vis, s, c);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int m = rooms.size();
        vector <int> vis(m, 0);
        int s = (m) * (m-1) / 2;
        traverse(rooms, vis, s, 0);
        return s == 0;
    }
};