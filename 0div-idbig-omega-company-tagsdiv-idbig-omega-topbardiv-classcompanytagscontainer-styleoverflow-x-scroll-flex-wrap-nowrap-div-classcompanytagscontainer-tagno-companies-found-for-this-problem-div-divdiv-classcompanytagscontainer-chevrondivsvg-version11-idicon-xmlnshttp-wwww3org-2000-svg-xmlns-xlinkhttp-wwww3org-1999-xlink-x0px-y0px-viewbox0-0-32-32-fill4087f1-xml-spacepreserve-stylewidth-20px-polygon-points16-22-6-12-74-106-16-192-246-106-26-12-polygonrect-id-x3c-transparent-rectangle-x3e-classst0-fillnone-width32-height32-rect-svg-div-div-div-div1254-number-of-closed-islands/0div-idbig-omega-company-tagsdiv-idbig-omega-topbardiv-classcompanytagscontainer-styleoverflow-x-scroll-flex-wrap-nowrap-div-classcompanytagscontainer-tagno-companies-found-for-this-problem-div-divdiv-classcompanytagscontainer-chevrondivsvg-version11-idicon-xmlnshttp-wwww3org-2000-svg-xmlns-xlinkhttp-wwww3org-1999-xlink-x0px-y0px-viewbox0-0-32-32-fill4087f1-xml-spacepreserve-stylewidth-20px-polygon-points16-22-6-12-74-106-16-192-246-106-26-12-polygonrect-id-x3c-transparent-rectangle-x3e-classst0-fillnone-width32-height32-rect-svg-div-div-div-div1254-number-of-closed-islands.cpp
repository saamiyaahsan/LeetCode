class Solution {
public:
    
    void dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 0)
        {
            return;
        }
        
        grid[i][j] = 2;
        
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
        
    }
    
    void helper(vector<vector<int>>& grid,int i,int j)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 0)
        {
            return;
        }
        
        grid[i][j] = 3;
        
        helper(grid,i+1,j);
        helper(grid,i-1,j);
        helper(grid,i,j+1);
        helper(grid,i,j-1);
    }
    int closedIsland(vector<vector<int>>& grid) {
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if((i == 0 || i == grid.size()-1 || j == 0 || j == grid[0].size()-1) && grid[i][j] == 0)
                {
                    dfs(grid,i,j);            
                }
            }
        }
        
        int cnt = 0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 0)
                {
                    cnt++;
                    helper(grid,i,j);      
                }
            }
        }
        
        return cnt;
    }
};