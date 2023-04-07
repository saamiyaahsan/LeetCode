class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        
        queue<pair<pair<int,int>,int>>q;
        
        q.push({{0,0},0});
        
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>>visited(n,vector<int>(m,0));
         visited[0][0] = 1;
        vector<int>drow = {-2,-2,-1,-1,1,1,2,2};
        vector<int>dcol = {-1,1,2,-2,2,-2,1,-1};
        
        while(q.empty() != true)
        {
            auto p = q.front();
            q.pop();
            int row = p.first.first;
            int col = p.first.second;
            int step = p.second;
            
            for(int i=0;i<drow.size();i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow >= 0 && nrow <= grid.size()-1 && ncol >= 0 && ncol <= grid[0].size()-1 && grid[nrow][ncol] == step + 1)
                {
                    q.push({{nrow,ncol},step+1});
                    visited[nrow][ncol] = 1;          
                }
                
            }
        }
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
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