class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int j=0,cnt=0,prod=1;
        
        if(k <= 1)
        {
            return 0;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            prod = prod*nums[i];
            
            while(prod >= k)
            {
                prod = prod/nums[j];
                j++;
            }
            
            cnt = cnt + (i-j+1);
        }
        
        return cnt;
    }
};