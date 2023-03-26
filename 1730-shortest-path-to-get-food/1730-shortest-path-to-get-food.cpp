class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        
        queue<pair<int,int>>q;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == '*')
                {
                    q.push({i,j});
                }
            }
        }
        
        int cnt = 0;
        
        vector<int>drow = {-1,0,1,0};
        vector<int>dcol = {0,1,0,-1};
        while(q.empty() != true)
        {
            cnt++;
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                auto p = q.front();
                int row = p.first;
                int col = p.second;
                q.pop();
                for(int i = 0;i < drow.size();i++)
                {
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];
                
                    if(nrow >= 0 && nrow <= grid.size()-1 && ncol >= 0 && ncol <= grid[0].size()-1 && grid[nrow][ncol] == 'O')
                    {
                        grid[nrow][ncol] = 'X';
                        q.push({nrow,ncol});
                    }
                    
                    else if(nrow >= 0 && nrow <= grid.size()-1 && ncol >= 0 && ncol <= grid[0].size()-1 && grid[nrow][ncol] == '#')
                    {
                        return cnt;
                    }
                }
            }
        }
        
        return -1;
    }
};