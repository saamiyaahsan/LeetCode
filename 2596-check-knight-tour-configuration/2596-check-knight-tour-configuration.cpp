class Solution {
public:
    
    void dfs(vector<vector<int>>& grid,int i,int j,int step,int &cnt)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != step + 1)
        {
            return;
        }
        
        cnt++;
        int parent_value = grid[i][j];
        grid[i][j] =0;
        
        dfs(grid,i+2,j+1,parent_value,cnt);
        dfs(grid,i+2,j-1,parent_value,cnt);
        dfs(grid,i-2,j+1,parent_value,cnt);
        dfs(grid,i-2,j-1,parent_value,cnt);
        dfs(grid,i+1,j+2,parent_value,cnt);
        dfs(grid,i+1,j-2,parent_value,cnt);
        dfs(grid,i-1,j-2,parent_value,cnt);
        dfs(grid,i-1,j+2,parent_value,cnt);
        
        //p || q || r || s || a || b || c || d;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        
        int cnt = 0,step = -1;
        
        dfs(grid,0,0,step,cnt);
        
        if(cnt == grid.size()*grid[0].size())
        {
            return true;
        }
        
        return false;
    }
};