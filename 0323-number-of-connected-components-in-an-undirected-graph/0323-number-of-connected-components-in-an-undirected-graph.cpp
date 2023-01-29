class Solution {
public:
    
    void dfs(int node,vector<int>& vis,vector<vector<int>>&adj)
    {
        vis[node] = 1;
        
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs(it,vis,adj);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(n);
        
        vector<int>vis(n,0);
        
        int cnt = 0;
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i=0;i<vis.size();i++)
        {
            if(vis[i] == 0)
            {
                cnt++;
                dfs(i,vis,adj);
            }
        }
        
        return cnt;
    }
};