class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        queue<pair<pair<int,int>,int>>q;
        
        int cntZero = 0,cntOne = 0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({{i,j},0});
                    cntOne++;
                }
                
                else
                {
                    cntZero++;
                }
            }
        }
        
        int ans = INT_MIN;
        
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
                int dist = x.second;
                ans = max(ans,dist);
                
                for(int j=0;j<drow.size();j++)
                {
                    int nrow = row + drow[j];
                    int ncol = col + dcol[j];
                    
                    if(nrow >= 0 && nrow <= grid.size()-1 && ncol >= 0 && ncol <= grid[0].size()-1 && grid[nrow][ncol] == 0)
                    {
                        grid[nrow][ncol] = 1;
                        q.push({{nrow,ncol},dist+1});
                    }
                }
            }
        }
        
        if(cntZero == 0 || cntOne == 0)
        {
           return -1;    
        }
        
        return ans;
    }
};