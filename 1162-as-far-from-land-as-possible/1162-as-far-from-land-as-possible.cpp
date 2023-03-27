class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
         
        queue<pair<pair<int,int>,int>>q;
        
        int visited[grid.size()][grid[0].size()];
        
        int cnt = 0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                   cnt++; 
                   q.push({{i,j},0});
                   visited[i][j] = 1; 
                }
                
                else
                {
                    visited[i][j] = -1;
                }
            }
        }
        
        int ans = 0;
        
        vector<int>drow = {-1,0,1,0};
        vector<int>dcol = {0,1,0,-1};
        while(q.empty() != true)
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                auto p = q.front();
                q.pop();
                
                int row = p.first.first;
                int col = p.first.second;
                int dist = p.second;
                ans = max(ans,dist);
                for(int i=0;i<drow.size();i++)
                {
                    int nrow = drow[i] + row;
                    int ncol = dcol[i] + col;
                    
                    if(nrow >= 0 && nrow <= grid.size()-1 && ncol >= 0 && ncol <= grid[0].size()-1 && grid[nrow][ncol] == 0)
                    {
                        q.push({{nrow,ncol},dist + 1});
                        grid[nrow][ncol] = 1;
                    }
                }
            }
        }
        
        if(cnt == (grid.size()*grid[0].size()) || cnt == 0)
        {
            return -1;
        }
        return ans;
    }
};