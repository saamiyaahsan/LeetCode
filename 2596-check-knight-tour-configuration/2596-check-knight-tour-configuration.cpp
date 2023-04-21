class Solution {
public:
    
    void dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& visited,int step)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j] == 1 || grid[i][j] != step + 1)
        {
            return;
        }
        
        visited[i][j] = 1;
        
        dfs(grid,i-2,j-1,visited,step + 1);
        dfs(grid,i+2,j+1,visited,step + 1);
        dfs(grid,i-2,j+1,visited,step + 1);
        dfs(grid,i+2,j-1,visited,step + 1);
        dfs(grid,i-1,j-2,visited,step + 1);
        dfs(grid,i+1,j+2,visited,step + 1);
        dfs(grid,i-1,j+2,visited,step + 1);
        dfs(grid,i+1,j-2,visited,step + 1);
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        
        int n = grid.size(),m = grid[0].size();
        
        int step = -1;
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        dfs(grid,0,0,visited,step);
        
        for(int i=0;i<visited.size();i++)
        {
            for(int j=0;j<visited[0].size();j++)
            {
                if(visited[i][j] == 0)
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};