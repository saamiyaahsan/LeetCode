class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
     
        vector<vector<pair<int,double>>>adj(n);
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        // max-heap is used b/c maximum probability is being asked
       
        priority_queue<pair<double,int>>pq;
        
        vector<double>probability(n,0);
        
        probability[start_node] = 1;
        
        pq.push({1,start_node});
        
        while(pq.empty() != true)
        {
            auto it = pq.top();
            pq.pop();
            
            double probab = it.first;
            int node = it.second;
            
            for(auto i : adj[node])
            {
                int adjNode = i.first;
                double currProbability = i.second;
                
                if(currProbability*probab > probability[adjNode])
                {
                    probability[adjNode] = currProbability*probab;
                    pq.push({probability[adjNode],adjNode});
                }
            }
        }
        
        if(probability[end_node] == 0)
        {
            return 0;
        }
        
        return probability[end_node];
    }
};