class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        
        if(intervals.size() == 0 || intervals.size() == 1)
        {
            return true;    
        }
        
        for(int i=0;i<intervals.size();i++)
        {
            swap(intervals[i][0],intervals[i][1]);
        }
        
        sort(intervals.begin(),intervals.end());
        
        for(int i=0;i<intervals.size();i++)
        {
            swap(intervals[i][0],intervals[i][1]);
        }
        
        int i = 0;
        
        for(int j=1;j<intervals.size();j++)
        {
            if(intervals[i][1] <= intervals[j][0])
            {
                i = j;
            }
            
            else
            {
                return false;
            }
        }
        
        return true;
    }
};