class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        queue<pair<pair<int,int>,int>>q;
        
        if(grid.size() == 1 && grid[0].size() == 1 && grid[0][0] == 0)
        {
            return 1;
        }
        
        if(grid[0][0] == 1 || grid[grid.size()-1][grid[0].size()-1] == 1)
        {
            return -1;
        }
        
        q.push({{0,0},1});
        
        vector<int>drow = {-1,-1,-1,0,0,1,1,1};
        vector<int>dcol = {-1,0,1,-1,1,-1,0,1};
        
        while(q.empty() != true)
        {
            auto x = q.front();
            int row = x.first.first;
            int col = x.first.second;
            int dist = x.second;
            q.pop();
            
            for(int i=0;i<drow.size();i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow >= 0 && nrow <= grid.size()-1 && ncol >= 0 && ncol <= grid[0].size()-1 && grid[nrow][ncol] == 0)
                {
                    grid[nrow][ncol] = 1;
                    q.push({{nrow,ncol},dist+1});
                }
                
                if(nrow == grid.size()-1 && ncol == grid[0].size()-1)
                {
                    return dist + 1;
                }
            }
        }
        
        return -1;
    }
};