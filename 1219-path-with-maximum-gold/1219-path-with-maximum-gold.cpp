class Solution {
public:
     int dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& visited)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || visited[i][j] == 1)
        {
            return 0;
        }
        
        visited[i][j] = 1;
        
        int ans = grid[i][j] + max({dfs(grid,i,j-1,visited),dfs(grid,i,j+1,visited),dfs(grid,i-1,j,visited),dfs(grid,i+1,j,visited)});
        
         visited[i][j] = 0;  
         
        return ans;
      
     }
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int ans = INT_MIN;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] != 0)
                {
                    vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
                    ans = max(ans,dfs(grid,i,j,visited));
                }
            }
        }
        
        if(ans == INT_MIN)
        {
            return 0;
        }
        return ans;
    }
};