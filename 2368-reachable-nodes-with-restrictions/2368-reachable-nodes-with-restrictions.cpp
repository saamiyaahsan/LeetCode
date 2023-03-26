class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        vector<vector<int>>adj(n);
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        map<int,int>mp;
        
        for(int i=0;i<restricted.size();i++)
        {
            mp[restricted[i]] = 1;
        }
        
        vector<int>visited(n,0);
        
        queue<int>q;
        
        q.push(0);
        
        visited[0] = 1;
        
        int cnt = 0;
        
        while(q.empty() != true)
        {
            int val = q.front();
            q.pop();
             cnt++;
                for(auto it : adj[val])
                {
                    if(visited[it] == 0 && mp[it] == 0)
                    {
                        q.push(it);
                        visited[it] = 1;
                    }
                }
        }
        
        return cnt;
    }
};