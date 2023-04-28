class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int ans = INT_MIN,p=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(ans < nums[i])
            {
                ans = nums[i];
                p = i;
            }
        }
        
        return p;
    }
};