class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<pair<int,int>,int>>q;
        
        int cntfresh = 0,cnt = 0,ans = INT_MIN;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i,j},0});
                }
                
                else if(grid[i][j] == 1)
                {
                    cntfresh++;
                }
            }
        }
        
        vector<int>drow = {-1,0,1,0};
        vector<int>dcol = {0,1,0,-1};
        
            while(q.empty() != true)
            {
                int n = q.size();
                
                for(int i=0;i<n;i++)
                {
                                   auto x = q.front();
                q.pop();
                int row = x.first.first;
                int col = x.first.second;
                int time = x.second;
                
                ans = max(ans,time);
                
                for(int j=0;j<drow.size();j++)
                {
                    int nrow = row + drow[j];
                    int ncol = col + dcol[j];
                    
                    if(nrow >= 0 && nrow <= grid.size()-1 && ncol >= 0 && ncol <= grid[0].size()-1 && grid[nrow][ncol] == 1)
                    {
                        q.push({{nrow,ncol},time+1});
                        grid[nrow][ncol] = 2;
                        cnt++;
                    }
                    
                }        
                }
            }
        
        if(cnt != cntfresh)
        {
            return -1;
        }
        
        if(ans == INT_MIN)
        {
            return 0;
        }
        return ans;
    }
};