class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int>indegree(n,0);
        
        vector<vector<int>>adj(n);
        
        for(int i=0;i<n;i++)
        {
            for(auto it : graph[i])
            {
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int>q;
        
        vector<bool>safe(n);
        
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
            safe[node] = true;
            
            for(auto it : adj[node])
            {
                indegree[it]--;
                
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        
        vector<int>safeNodes;
        
        for(int i=0;i<n;i++)
        {
            if(safe[i] == true)
            {
                safeNodes.push_back(i);
            }
        }
        
        return safeNodes;
    }
};