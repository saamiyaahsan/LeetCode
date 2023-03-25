class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<pair<int,int>,int>>q;
        
        int visited[n][m];
        
        int c = 0,cnt = 0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }
                
                else if(grid[i][j] == 1)
                {
                    cnt++;
                    visited[i][j] = 0;
                }
                
                else
                {
                    visited[i][j] = 0;
                }
            }
        }
        
        vector<int>drow = {-1,0,1,0};
        vector<int>dcol = {0,1,0,-1};
        
        int ans = 0;
        
        while(q.empty() != true)
        {
            auto p = q.front();
            q.pop();
            int row = p.first.first;
            int col = p.first.second;
            int time = p.second;
            
            ans = max(ans,time);
            
            for(int i=0;i<drow.size();i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow >= 0 && nrow <= grid.size()-1 && ncol >= 0 && ncol <= grid[0].size()-1 && visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
                {
                    q.push({{nrow,ncol},time+1});
                    visited[nrow][ncol] = 2;
                    c++;
                }
            }
        }
        
        if(c != cnt)
        {
           return -1;    
        }
        
        return ans;
    }
};