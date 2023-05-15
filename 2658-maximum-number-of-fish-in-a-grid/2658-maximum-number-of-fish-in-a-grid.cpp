class Solution {
public:
    
    int ans = 0;
    
    int dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] <= 0)
        {
            return 0;
        }
        
        int temp = grid[i][j];
        
        grid[i][j] = -1;
        
        ans = dfs(grid,i-1,j)+dfs(grid,i+1,j)+dfs(grid,i,j-1) + dfs(grid,i,j+1) + temp;
       
        return ans;
         
          grid[i][j] = temp; 
    }
    int findMaxFish(vector<vector<int>>& grid) {
        
        int n = grid.size() , m = grid[0].size();
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        int cnt = 0,res = 0,c = 0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 0)
                {
                    cnt++;
                }
                
                else
                {
                    c++;
                    res = max(res,dfs(grid,i,j));
                }
            }
        }
        
        if(c == 0)
        {
            return 0;
        }
        
        return res;
    }
};