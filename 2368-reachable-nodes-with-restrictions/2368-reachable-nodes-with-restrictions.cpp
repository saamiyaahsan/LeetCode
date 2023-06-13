class Solution {
public:
    
    void dfs(int node,vector<vector<int>>& adj,unordered_map<int,int>& mp,vector<int>& visited,int& cnt)
    {
        visited[node] = 1;
        cnt++;
        
        for(auto it : adj[node])
        {
            if(visited[it] == 0 && mp.find(it) == mp.end())
            {
                dfs(it,adj,mp,visited,cnt);
            }
        }
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
            mp[restricted[i]] = 1;
        }
        
        int cnt = 0;
        
        dfs(0,adj,mp,visited,cnt);
    
       return cnt;
    }
};