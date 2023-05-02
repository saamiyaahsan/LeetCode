class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int>ans(nums.begin(),nums.end());
        
        sort(nums.begin(),nums.end());
        
        int p=-1,q=-1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] != ans[i])
            {
                p = i;
                break;
            }
        }
        
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i] != ans[i])
            {
                q = i;
                break;
            }
        }
        
        if(p == -1 && q == -1)
        {
            return 0;
        }
        
        return q-p+1;
    }
};