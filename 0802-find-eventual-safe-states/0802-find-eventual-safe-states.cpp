class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
         
        int n = graph.size();
        
        vector<vector<int>>adj(n); // for the reversal of graph
        
        vector<int>indegree(n,0);
        
        for(int i=0;i<n;i++)
        {
            for(auto it : graph[i])
            {
                adj[it].push_back(i);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(auto it : adj[i])
            {
               indegree[it]++;    
            }
            
        }
        
        queue<int>q;
        vector<int>res;
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        while(q.empty() != true)
        {
            int node = q.front();
            q.pop();
            
            res.push_back(node);
            
            for(auto it : adj[node])
            {
                indegree[it]--;
                
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        
        sort(res.begin(),res.end());
        
        return res;
    }
};