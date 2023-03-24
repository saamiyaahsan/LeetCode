class Solution {
public:
    
    int dfs(vector<vector<int>>& grid,int i,int j,int ans,vector<vector<int>>& visited)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j] == 1 || grid[i][j] == 0)
        {
            return 0;    
        }
        
        visited[i][j] = 1;
        
        ans = grid[i][j] + max({dfs(grid,i,j-1,ans,visited),dfs(grid,i,j+1,ans,visited),dfs(grid,i-1,j,ans,visited),dfs(grid,i+1,j,ans,visited)});
        
        visited[i][j] = 0;
        
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        
//         vector<vector<int>>visited;
        
//         for(int i=0;i<visited.size();i++)
//         {
//             for(int j=0;j<visited[0].size();j++)
//             {
//                 visited.push_back(0);
//             }
//         }
        
        int n = grid.size(), m = grid[0].size();
        
        int ans = 0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                vector<vector<int>>visited(n,vector<int>(m));
                
                if(grid[i][j] != 0)
                {
                   int p = dfs(grid,i,j,ans,visited);   
                   ans = max(ans,p);       
                }
                
            }
        }
        
        return ans;
    }
};