class Solution {
public:
    
    void dfs(vector<vector<int>>& adj,int node,vector<int>& visited)
    {
        visited[node] = 1;
        
        for(auto it : adj[node])
        {
            if(visited[it] == 0)
            {
                dfs(adj,it,visited);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n-1)
        {
            return -1;
        }
        
        vector<vector<int>>adj(n);
        
        vector<int>visited(n,0);
        
        int cnt = 0;
        
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        dfs(adj,0,visited);
        
        for(int i=0;i<visited.size();i++)
        {
            if(visited[i] == 0)
            {
                cnt++;
                dfs(adj,i,visited);
            }
        }
        
        return cnt;
        
    }
};