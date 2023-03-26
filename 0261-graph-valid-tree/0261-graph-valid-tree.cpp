class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(n);
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<pair<int,int>>q;
        
        vector<int>visited(n,0);
        
        q.push({0,-1});
        
        visited[0] = 1;
        
        while(q.empty() != true)
        {
            auto p = q.front();
            q.pop();
            int node = p.first;
            int parent = p.second;
            
            for(auto it : adj[node])
            {
                if(visited[it] == 0)
                {
                    visited[it] = 1;
                    q.push({it,node});
                }
                
                else if(visited[it] == 1 && it != parent)
                {
                    return false;
                }
            }    
        }
        
        for(int i=0;i<visited.size();i++)
        {
            if(visited[i] == 0)
            {
                return false;
            }
        }
        
        return true;
    }
};