class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        int i,j,res=-1;
        
        i=0;
        j=nums.size()-1;
        
        while(i < j)
        {
            if(nums[i] + nums[j] == k)
            {
                j--;
            }
            
            else if(nums[i] + nums[j] < k)
            {
                res = max(res,nums[i] + nums[j]);
                i++;
            }
            
            else
            {
                j--;
            }
        }
        
        return res;
    }
};