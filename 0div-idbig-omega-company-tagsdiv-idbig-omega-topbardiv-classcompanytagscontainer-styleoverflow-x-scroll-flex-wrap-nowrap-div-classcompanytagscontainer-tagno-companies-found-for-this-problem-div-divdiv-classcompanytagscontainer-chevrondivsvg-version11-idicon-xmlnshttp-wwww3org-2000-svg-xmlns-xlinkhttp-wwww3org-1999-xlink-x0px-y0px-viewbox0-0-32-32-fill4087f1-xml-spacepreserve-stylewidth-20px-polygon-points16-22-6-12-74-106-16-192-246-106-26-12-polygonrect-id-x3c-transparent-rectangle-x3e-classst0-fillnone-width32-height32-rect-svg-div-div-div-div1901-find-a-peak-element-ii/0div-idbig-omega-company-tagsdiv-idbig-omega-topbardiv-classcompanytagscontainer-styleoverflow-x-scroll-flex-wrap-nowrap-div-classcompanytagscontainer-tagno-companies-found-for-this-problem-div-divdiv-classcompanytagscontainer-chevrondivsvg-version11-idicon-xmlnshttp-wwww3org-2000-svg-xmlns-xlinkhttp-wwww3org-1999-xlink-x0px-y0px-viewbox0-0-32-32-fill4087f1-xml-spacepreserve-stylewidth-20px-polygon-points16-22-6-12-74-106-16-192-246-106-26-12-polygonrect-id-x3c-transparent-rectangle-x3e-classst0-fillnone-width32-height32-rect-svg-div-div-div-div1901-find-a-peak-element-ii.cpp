class Solution {
public:
    
    bool ishelper(vector<vector<int>>& mat,int row,int col)
    {
        int drow[] = {-1,0,0,1};
        int dcol[] = {0,-1,1,0};
        
        for(int i=0;i<4;i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            if(nrow >= 0 && nrow <= mat.size()-1 && ncol >= 0 && ncol <= mat[0].size()-1 && mat[nrow][ncol] > mat[row][col])
            {
                return false;
            }
        }
        
        return true;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(ishelper(mat,i,j) == true)
                {
                    return {i,j};
                }
            }
        }
        
        return {-1,-1};
    }
};