class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
       
        queue<int>q;
        
        vector<int>visited(n,0);
        
        unordered_map<int,int>mp;
        
        vector<vector<int>>adj(n);
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i=0;i<restricted.size();i++)
        {
            mp[restricted[i]] = 1;
        }
        
        int ans = 1;
        
        visited[0] = 1;
        
        q.push(0);
        
        while(q.empty() != true)
        {
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node])
            {
                if(visited[it] == 0)
                {
                    if(mp.find(it) == mp.end())
                    {
                      visited[it] = 1;   
                      ans++;
                      q.push(it);
                    }     
                }
               
            }
        }
        
        return ans;
    }
};