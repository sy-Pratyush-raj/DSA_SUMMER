//                     547. Number of Provinces

class Solution {
public:
    void dfs(int i, vector<vector<int>>& g, vector<int>& vis){
        vis[i] = 1;
        for(int j = 0; j < g.size(); j++){
            if(g[i][j] == 1 && !vis[j])
                dfs(j, g, vis);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int count = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, isConnected, vis);
                count++;
            }
        }
        return count;
    }
};