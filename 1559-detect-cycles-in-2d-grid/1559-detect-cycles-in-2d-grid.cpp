class Solution {
public:
    
    bool dfs(vector<vector<char>>& grid,int i,int j,char src,vector<vector<int>>& visited)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != src)
        {
            return false;
        }
        
        if(visited[i][j] == 1)
        {
            return true;
        }
        
        char temp = grid[i][j];
        grid[i][j] = '#';
        visited[i][j] = 1;
        
        bool p = dfs(grid,i-1,j,src,visited);
        bool q = dfs(grid,i+1,j,src,visited);
        bool r = dfs(grid,i,j-1,src,visited);
        bool s = dfs(grid,i,j+1,src,visited);
        
        grid[i][j] = temp;
        
        return p || q || r || s;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        
        int n = grid.size(),m = grid[0].size();
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                char src = grid[i][j];
                
                if(visited[i][j] == 0 && dfs(grid,i,j,src,visited) == true)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};