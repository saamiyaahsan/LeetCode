class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
     
        sort(nums.begin(),nums.end());
        
        int i,j,ans=-1;
        
        i=0;
        j=nums.size()-1;
        
        while(i<j)
        {
            if(nums[i]+nums[j] < k)
            {
                ans = max(ans,nums[i]+nums[j]);
                i++;
            }
            
            else
            {
                j--;
            }
        }
        
        return ans;
    }
};