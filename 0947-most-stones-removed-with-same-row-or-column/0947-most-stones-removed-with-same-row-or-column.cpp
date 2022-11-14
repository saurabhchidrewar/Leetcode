class Solution {
public:
    void dfs(vector<vector<int>>&stones,int ind,vector<bool>&visited,int n){
        visited[ind]=true; //marking the stone as visited
        //now search for the stones which exist in same row or column and do a dfs for those stones as well
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(stones[i][0]==stones[ind][0] || stones[i][1]==stones[ind][1]){
                    dfs(stones,i,visited,n);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool>visited(n,false); //to check whether the stone is visited
        int ans=n;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(stones,i,visited,n);
                ans--;//we need to leave one stone for a tree
            }
        }
        return ans;
    }
};