class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        long long sum = 0,ans = 0,j = 0,i=0;
        
        for(i=0;i<nums.size();i++)
        {
            sum = sum + nums[i];
            
            while((i-j+1)*nums[i] - sum > k)
            {
                sum = sum - nums[j];
                j++;
            }
            
            ans = max(ans,i-j+1);
        }
        
        return ans;
    }
};