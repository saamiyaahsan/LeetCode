class Solution {
public:
    
    bool dfs(vector<vector<char>>& grid,int i,int j,vector<vector<int>>& visited,char src)
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
        
        grid[i][j] = '*';
        visited[i][j] = 1;
        
        bool p = dfs(grid,i-1,j,visited,src);
        bool q = dfs(grid,i+1,j,visited,src);
        bool r = dfs(grid,i,j-1,visited,src);
        bool s = dfs(grid,i,j+1,visited,src);
        
        grid[i][j] = temp;
        
        return p || q || r || s;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        
        int n = grid.size(),m = grid[0].size();
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                char src = grid[i][j];
                if(visited[i][j] == 0 && dfs(grid,i,j,visited,src) == true)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};