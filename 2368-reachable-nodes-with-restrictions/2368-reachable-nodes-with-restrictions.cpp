class Solution {
public:
    
   void dfs(vector<vector<int>>& adj,int node,vector<int>& visited,int & cnt)
    {
        visited[node] = 1;
        
        cnt++;
        
           for(auto it : adj[node])
            {
               if(visited[it] == 0)
               {
                   dfs(adj,it,visited,cnt);    
               }
               
            }
        
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        vector<vector<int>>adj(n);
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>visited(n,0);
        
        for(auto it : restricted)
        {
            visited[it] = 1;        
        }
        
        int cnt = 0;
        
        dfs(adj,0,visited,cnt);
        
        return cnt;
    }
};