class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& grid) {
       
        queue<pair<int,int>>q;
        
        q.push({0,0});
        
        int n = grid.size(),m = grid[0].size();
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        visited[0][0] = 1;
        
        int c = 0;
        
        vector<int>res;
        vector<int>ans;
        
        vector<int>drow = {1,0};
        vector<int>dcol = {0,1};
        while(q.empty() != true)
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                auto p = q.front();
                int row = p.first;
                int col = p.second;
                q.pop();
                res.push_back(grid[row][col]);
                
                for(int i=0;i<drow.size();i++)
                {
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];
                    
                    if(nrow >= 0 && nrow <= grid.size()-1 && ncol >= 0 && ncol <= grid[0].size()-1 && visited[nrow][ncol] == 0)
                    {
                        q.push({nrow,ncol});
                        visited[nrow][ncol] = 1;
                    }
                }
            }
            
            if(c % 2 == 1)
            {
                reverse(res.begin(),res.end());
                
                for(auto it : res)
                {
                    ans.push_back(it);
                    res.clear();
                }
                c++;
            }
            
            else
            {
                for(auto it : res)
                {
                    ans.push_back(it);
                    res.clear();
                }
                
                c++;
            }
        }
        
        return ans;
    }
};