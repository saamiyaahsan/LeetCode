class Solution {
public:
    
    void helper(vector<vector<pair<int,int>>>& adj,int src,vector<int>& visited,int& cnt)
    {
        visited[src] = 1;
        
        for(auto it : adj[src])
        {
            if(visited[it.first] == 0)
            {
                if(it.second == 1)
                {
                    cnt++;
                }
                
                  helper(adj,it.first,visited,cnt);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<pair<int,int>>>adj(n);
        
        int cnt = 0;
        
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back({connections[i][1],1});
            adj[connections[i][1]].push_back({connections[i][0],0});
        }
        
        vector<int>visited(n,0);
        
        helper(adj,0,visited,cnt);
        
        return cnt;
    }
};