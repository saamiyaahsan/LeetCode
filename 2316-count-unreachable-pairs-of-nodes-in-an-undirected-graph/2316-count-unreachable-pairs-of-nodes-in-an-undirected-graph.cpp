class Solution {
public:
    
    int dfs(int node,vector<vector<int>>& adj,vector<int>& visited)
    {
        visited[node] = 1;
        
        int count = 1;
        
        for(auto it : adj[node])
        {
            if(visited[it] == 0)
            {
                count = count + dfs(it,adj,visited);
            }
        }
        
        // returns the size of the component
        
        return count;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
    
        vector<vector<int>>adj(n);
        
        vector<int>visited(n,0);
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        long long ans = 0,remainingNodes = n,sizeOfComponent = 0,countNoOfPairs=0;
        
        for(int i=0;i<n;i++)
        {
            if(visited[i] == 0)
            {
                 sizeOfComponent = dfs(i,adj,visited);
                 countNoOfPairs = sizeOfComponent*(remainingNodes-sizeOfComponent);
                ans = ans + countNoOfPairs;
                remainingNodes = remainingNodes - sizeOfComponent;
            }
        }
        
        return ans;
    }
};