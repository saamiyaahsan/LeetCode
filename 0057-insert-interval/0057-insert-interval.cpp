class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>>ans;
        
        intervals.push_back(newInterval);
        
        sort(intervals.begin(),intervals.end());
        
        int j=0;
        
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