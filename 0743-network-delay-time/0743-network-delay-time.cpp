class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>>adj(n+1);
        
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
           // adj[times[i][1]].push_back({times[i][0],times[i][2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>dist(n+1,INT_MAX);
        
        dist[k] = 0;
        
        pq.push({dist[k],k});
        
        while(pq.empty() != true)
        {
            auto p = pq.top();
            pq.pop();
            
            int node = p.second;
            int distance = p.first;
            
            for(auto it : adj[node])
            {
                int edge_weight = it.second;
                int adj_node = it.first;
                
                if(distance + edge_weight < dist[adj_node])
                {
                    dist[adj_node] = distance + edge_weight;
                    pq.push({dist[adj_node],adj_node});
                }
            }
        }
        
        int ans = 0;
        
        for(int i=1;i<=n;i++)
        {
//             if(dist[i] == INT_MAX)
//             {
//                 return -1;
//             }
            
//            else
    
                ans = max(ans,dist[i]);
            
        }
        
        if(ans == INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};