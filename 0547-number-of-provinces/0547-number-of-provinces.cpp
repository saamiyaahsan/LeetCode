class Solution {
public:
    
    void dfs(int node,vector<int>& visited,vector<int>adj[])
    {
       visited[node] = 1;
       
       for(auto it : adj[node]) 
       {
           if(visited[it] == 0)
           {
               dfs(it,visited,adj);
           }
       }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int cnt = 0;
        
        vector<int>adj[isConnected[0].size()];
        
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected[0].size();j++)
            {
                if(isConnected[i][j] == 1 && i != j)
                {
                   adj[i].push_back(j);
                   adj[j].push_back(i);  
                }
            }
        }
        
        vector<int>visited(isConnected[0].size(),0);
        
        for(int i=0;i<isConnected[0].size();i++)
        {
            if(visited[i] == 0)
            {
                cnt++;
                dfs(i,visited,adj);
            }
        }
    return cnt;
    }
};