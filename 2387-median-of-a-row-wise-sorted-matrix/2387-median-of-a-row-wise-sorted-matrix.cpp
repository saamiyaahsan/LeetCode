class Solution {
public:
    int matrixMedian(vector<vector<int>>& grid) {
        
        vector<int>res;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                res.push_back(grid[i][j]);
            }
        }
        
        sort(res.begin(),res.end());
        
        return res[(res.size()-1)/2];
        
    }
};