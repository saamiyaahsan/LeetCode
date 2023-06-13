class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        vector<vector<int>>adj(n);
        
        unordered_map<int,int>mp;
        
        vector<int>visited(n,0);
        
        queue<int>q;
        
        int cnt = 0;
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i=0;i<restricted.size();i++)
        {
            mp[restricted[i]] = 1;
        }
        
        q.push(0);
        visited[0] = 1;
        cnt++;
        
        while(q.empty() != true)
        {
            int x = q.front();
            q.pop();
            
            for(auto it : adj[x])
            {
                if(visited[it] == 0 && mp.find(it) == mp.end())
                {
                    cnt++;
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        
        return cnt;
    }
};