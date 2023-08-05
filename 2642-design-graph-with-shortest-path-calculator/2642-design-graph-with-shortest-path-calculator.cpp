class Graph {
public:
    
    vector<pair<int,int>>adj[101];
    
    Graph(int n, vector<vector<int>>& edges) {

        for(auto it : edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        
        adj[edge[0]].push_back({edge[1],edge[2]});
        
    }
    
    int shortestPath(int node1, int node2) {
        
        vector<int>dist(101,1e9);
        
        dist[node1] = 0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({0,node1});
        
        while(pq.empty() != true)
        {
            auto it = pq.top();
            pq.pop();
            
            int dis = it.first;
            int node = it.second;
            
            for(auto i : adj[node])
            {
                int adjNode = i.first;
                int edgeWt = i.second;
                
                if(dis + edgeWt < dist[adjNode])
                {
                    dist[adjNode] = dis + edgeWt;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        
        if(dist[node2] == 1e9)
        {
            return -1;
        }
        
        return dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */