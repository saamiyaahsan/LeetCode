class Solution {
public:
    
    void dfs(vector<vector<int>>& grid1,vector<vector<int>>& grid2,int i,int j,bool& x)
    {
        if(i < 0 || i >= grid1.size() || j < 0 || j >= grid1[0].size() || grid2[i][j] == 0)
        {
            return;
        }
        
        if(grid1[i][j] != 1)
        {
            x = false;
        }
        
        grid2[i][j] = 0;
        
        dfs(grid1,grid2,i-1,j,x);
        dfs(grid1,grid2,i+1,j,x);
        dfs(grid1,grid2,i,j-1,x);
        dfs(grid1,grid2,i,j+1,x);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int cnt = 0;
        
        for(int i=0;i<grid1.size();i++)
        {
            for(int j=0;j<grid1[0].size();j++)
            {
                if(grid2[i][j] == 1)
                {
                    bool subisland = true;
                    dfs(grid1,grid2,i,j,subisland);
                    
                    if(subisland == true)
                    {
                        cnt++;
                    }
                }
            }
        }
        
        return cnt;
    }
};