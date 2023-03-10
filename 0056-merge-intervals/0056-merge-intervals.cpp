class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>>ans;
        
        int i=0,j=0;
        
        sort(intervals.begin(),intervals.end());
        
        ans.push_back(intervals[0]);
        
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0] <= ans[j][1])
            {
               ans[j][1] = max(intervals[i][1],ans[j][1]); 
            }
            
            else
            {
                ans.push_back(intervals[i]);
                j++;
            }
        }
        
        return ans;
        
    }
};