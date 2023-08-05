class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>>adj(n);
        
        for(int i=0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        queue<pair<int,pair<int,int>>>q;
        
        q.push({0,{src,0}});
        
        vector<int>dist(n,1e9);
        
        dist[src] = 0;
        
        while(q.empty() != true)
        {
            auto it = q.front();
            q.pop();
            
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            
            if(stops > k)
            {
                continue;
            }
            
            for(auto i : adj[node])
            {
                int adjNode = i.first;
                int edgeWt = i.second;
                
                if(cost + edgeWt < dist[adjNode] && stops <= k)
                {
                    dist[adjNode]  = cost + edgeWt;
                    q.push({stops+1,{adjNode,dist[adjNode]}});
                }
            }
        }
        
        if(dist[dst] == 1e9)
        {
            return -1;
        }
        
        return dist[dst];
    }
};