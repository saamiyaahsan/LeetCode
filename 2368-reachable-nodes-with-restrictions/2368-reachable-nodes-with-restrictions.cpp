class Solution {
public:
    
    int p = 0;
    
    int helper(vector<vector<int>>& adj,int node,vector<int>& visited,unordered_map<int,int>& mp)
    {
        visited[node] = 1;
        
        p = 1;
        
        for(auto it : adj[node])
        {
            if(visited[it] == 0)
            {
                if(mp.find(it) == mp.end())
                {
                  p = p + helper(adj,it,visited,mp);
                }       
            }
         }
        
        return p;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        vector<vector<int>>adj(n);
        
        unordered_map<int,int>mp;
        
        vector<int>visited(n,0);
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i=0;i<restricted.size();i++)
        {
            mp[restricted[i]] = 0;    
        }
        
        return helper(adj,0,visited,mp);
        
    }
};