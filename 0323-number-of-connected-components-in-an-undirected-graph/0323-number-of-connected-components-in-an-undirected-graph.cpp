class Solution {
public:
    
     void dfs(int u, vector<int>& vis,vector<vector<int>>& adj) 
     {
        vis[u] = 1;

        for (auto v : adj[u])
        {
            if (!vis[v])
            {
                dfs(v, vis, adj);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) 
    {
        vector<int> vis(n, 0);
        // let's convert edges into adj list
        vector<vector<int>> adj;
        adj.resize(n, vector<int>());

        for (int i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i, vis, adj);
                ++ans;
            }
        }

        return ans;
    }
};