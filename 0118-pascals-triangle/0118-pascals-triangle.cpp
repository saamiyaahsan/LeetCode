class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>>triangle;
        
        if(numRows == 0)
        {
            return triangle;
        }
        
        triangle.push_back({1});
        
        for(int i=1;i<numRows;i++)
        {
            vector<int>curr_row = triangle.back();
            vector<int>new_row = {1};
            
            for(int j=1;j<curr_row.size();j++)
            {
                new_row.push_back(curr_row[j] + curr_row[j-1]);
            }
            
            new_row.push_back(1);
            triangle.push_back(new_row);
        }
        
        return triangle;
    }
};