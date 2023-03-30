class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<vector<int>>adj(n);
        
        for(int i=0;i<manager.size();i++)
        {
            if(manager[i] != -1)
            {
                adj[i].push_back(manager[i]);
                adj[manager[i]].push_back(i);
            }
        }
        
        queue<pair<int,int>>q;
        
                vector<int>visited(n,0);
     
        
        q.push({headID,informTime[headID]});
        
        visited[headID] = 1;
           
        int ans = 0;
        
        while(q.empty() != true)
        {
            int N = q.size();
            
            for(int i = 0;i < N;i++)
            {
                auto p = q.front();
                q.pop();
                int node = p.first;
                int time = p.second;
                ans = max(ans,time);
                for(auto it : adj[node])
                {
                    if(visited[it] == 0)
                    {
                        visited[it] = 1;
                        q.push({it,time+informTime[it]});
                    }
                }
            }
        }
        
        return ans;
    }
};