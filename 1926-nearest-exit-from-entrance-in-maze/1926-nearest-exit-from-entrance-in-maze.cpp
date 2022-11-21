class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue <pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        
        int m = maze.size(), n = maze[0].size();        
        int moves = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            
            for (int z = 0; z < sz; z++) {
                auto [i, j] = q.front();
                q.pop();
                
                vector <pair<int, int>> path {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                
                for (auto &c: path) {
                    int x = c.first + i, y = c.second + j;
                    
                    if (x < 0 || y < 0 || x >= m || y >= n || maze[x][y] == '+')
                        continue;
                    
                    if (x == 0 || y == 0 || x == m-1 || y == n-1)
                        return moves + 1;
                    
                    maze[x][y] = '+';
                    q.push({x, y});
                }
            }
            
            moves++;
        }
        
        return -1;
    }
};