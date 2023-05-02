class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if(intervals.size() == 1)
        {
           return intervals;    
        }
        
        sort(intervals.begin(),intervals.end());
        
        int i=0;
        
        vector<vector<int>>output;
        
        output.push_back(intervals[0]);
        
        for(int j=1;j<intervals.size();j++)
        {
            if(output.back()[1] >= intervals[j][0])
            {
                output.back()[1] = max(output.back()[1],intervals[j][1]);
            }
            
            else
            {
                output.push_back(intervals[j]); 
            }
        }
        
        return output;
    }
};