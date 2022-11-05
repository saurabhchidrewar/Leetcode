struct Node {
    map<char,Node*> children;
    vector<int> inds;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // create a trie from the given words
        Node* root = new Node();

        for(int i=0; i<words.size(); i++) {
            Node* curr = root;

            for(char& c : words[i]) {
                if(not curr->children.count(c)) curr->children[c] = new Node();
                curr = curr->children[c];
            }

            // insert the index of the word
            curr->inds.push_back(i);
        }

        int m=board.size(), n=board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> moves{{1,0},{-1,0},{0,1},{0,-1}};
        vector<string> result;

        // backtracking function
        function<void(Node*,int,int)> solve = [&](Node* node, int i, int j) {
            // mark the current node as visited
            visited[i][j] = true;

            // check for any indices in the current node
            while(not node->inds.empty()) {
                result.push_back(words[node->inds.back()]);
                node->inds.pop_back();
            }

            // check the adjacent cell for any matches
            for(vector<int>& move : moves) {
                int ni = i+move[0];
                int nj = j+move[1];

                if(ni>=0 and ni<m and nj>=0 and nj<n and not visited[ni][nj] and node->children.count(board[ni][nj])) {
                    solve(node->children[board[ni][nj]], ni, nj);
                }
            }

            // mark the current cell as unvisited, backtrack
            visited[i][j] = false;
        };

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                // check if the character in the current cell is present in the trie
                if(root->children.count(board[i][j])) {
                    solve(root->children[board[i][j]], i, j);
                }
            }
        }

        return result;
    }
};