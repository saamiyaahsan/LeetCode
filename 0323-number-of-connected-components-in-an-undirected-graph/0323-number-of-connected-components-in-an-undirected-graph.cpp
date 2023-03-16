class Solution {
public:
    
    void dfs(int node,vector<int>& visited,vector<vector<int>>& adj)
    {
        visited[node] = 1;
        
        for(auto it : adj[node])
        {
            if(visited[it] == 0)
            {
                dfs(it,visited,adj);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(n);
        
        vector<int>visited(n,0);
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        int cnt = 0;
        
        for(int i=0;i<n;i++)
        {
            if(visited[i] == 0)
            {
                cnt++;
                dfs(i,visited,adj);
            }
        }
        
        return cnt;
    }
};