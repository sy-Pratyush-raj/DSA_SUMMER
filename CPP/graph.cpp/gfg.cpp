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
