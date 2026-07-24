//                          BFS of graph



class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<int> ans;
        vector<bool> visited(V, false);
        queue<int> q;

        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return ans;
    }
};


//                                 DFS of Graph

class Solution {
public:
    void dfsHelper(int node, vector<vector<int>>& adj,
                   vector<bool>& visited, vector<int>& result) {
        visited[node] = true;
        result.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, adj, visited, result);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<bool> visited(V, false);
        vector<int> result;

        dfsHelper(0, adj, visited, result);

        return result;
    }
};


//                       Undirected Graph Cycle

class Solution {
public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(V, 0);

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                queue<pair<int,int>> q; 
                q.push({i, -1});
                vis[i] = 1;

                while(!q.empty()){
                    auto [node, parent] = q.front();
                    q.pop();

                    for(int nei : adj[node]){
                        if(!vis[nei]){
                            vis[nei] = 1;
                            q.push({nei, node});
                        }
                        else if(nei != parent){
                            return true;  
                        }
                    }
                }
            }
        }
        return false;
    }
};


//                    Directed Graph Cycle



class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis, vector<int>& pathVis) {

        vis[node] = 1;
        pathVis[node] = 1;

        for(int nei : adj[node]) {

            if(!vis[nei]) {
                if(dfs(nei, adj, vis, pathVis))
                    return true;
            }
            else if(pathVis[nei]) {
                return true;   
            }
        }

        pathVis[node] = 0;   
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {

        vector<vector<int>> adj(V);

        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        vector<int> vis(V, 0), pathVis(V, 0);

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfs(i, adj, vis, pathVis))
                    return true;
            }
        }

        return false;
    }
};

