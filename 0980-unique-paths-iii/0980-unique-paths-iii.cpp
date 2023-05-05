class Solution {
public:
    
    int dfs(vector<vector<int>>& grid,int i,int j,int cnt,int &c)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == -1)
        {
            return 0;
        }
        
        if(grid[i][j] == 2)
        {
            cnt--;
            
            if(cnt == c)
            {
                return 1;
            }
            
            else
            {
                return 0;
            }
        }
        
        //cnt++;
        
        grid[i][j] = -1;
        
        int sum = dfs(grid,i-1,j,cnt+1,c) + dfs(grid,i+1,j,cnt+1,c) + dfs(grid,i,j-1,cnt+1,c) + dfs(grid,i,j+1,cnt+1,c);
        
        grid[i][j] = 0;
        
        return sum;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int sx,sy,c = 0,cnt=0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    sx = i;
                    sy = j;
                }
                
                else if(grid[i][j] == 0)
                {
                    c++;
                }
            }
        }
        
        return dfs(grid,sx,sy,cnt,c);
    }
};