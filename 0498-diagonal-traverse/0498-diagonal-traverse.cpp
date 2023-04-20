class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        int c = 0;
        
        vector<vector<int>>visited(mat.size(),(vector<int>(mat[0].size(),0)));
        
        queue<pair<int,int>>q;
        
        vector<int>ans;
        vector<int>res;
        
        q.push({0,0});
        
        vector<int>drow = {1,0};
        vector<int>dcol = {0,1};
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                auto p = q.front();
                q.pop();
                
                int row = p.first;
                int col = p.second;
                
                res.push_back(mat[row][col]);
                
                for(int i=0;i<drow.size();i++)
                {
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];
                    
                    if(nrow >= 0 && nrow <= mat.size()-1 && ncol >= 0 && ncol <= mat[0].size()-1 && visited[nrow][ncol] == 0)
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
                }
                
                res.clear();
                c++;
            }
            
            else
            {
                for(auto it : res)
                {
                    ans.push_back(it);
                }
                
                res.clear();
                c++;
            }
        }
        
        return ans;
    }
};