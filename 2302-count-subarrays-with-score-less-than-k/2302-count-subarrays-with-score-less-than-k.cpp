class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        long long ans = 0,score = 0,sum = 0;
        
        int j = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum = sum + nums[i];
            score = sum*(i-j+1);
            
            while(score >= k)
            {
                sum = sum - nums[j];
                j++;
                score = sum*(i-j+1);
            }
            
            ans = ans + (i-j+1);
        }
        
        return ans;
    }
};