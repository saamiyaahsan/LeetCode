class Solution {
public:
    
    bool dfs(vector<vector<int>>& adj,int node,vector<int>& color)
    {
        for(auto it : adj[node])
        {
            if(color[it] == -1)
            {
                color[it] = 1-color[node];
                if(dfs(adj,it,color) == false)
                {
                    return false;
                }
            }
            
            else if(color[it] == color[node])
            {
                return false;
            }
        }
        
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<vector<int>>adj(n);
        
        for(int i=0;i<dislikes.size();i++)
        {
            adj[dislikes[i][0]-1].push_back(dislikes[i][1]-1);
            adj[dislikes[i][1]-1].push_back(dislikes[i][0]-1);
        }
        
        vector<int>color(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(color[i] == -1)
            {
                color[i] = 0;
                if(dfs(adj,i,color) == false)
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};