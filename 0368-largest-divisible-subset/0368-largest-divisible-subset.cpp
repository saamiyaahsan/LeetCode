class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size(),max_index = 0;
        
        vector<int>ans;
        
        sort(nums.begin(),nums.end());
        
        vector<int>dp(n,1);
        
        vector<int>previous_index(n,-1);
        
        for(int i=1;i<nums.size();i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    previous_index[i] = j;
                }
            }
            
            if(dp[i] > dp[max_index])
            {
                max_index = i;
            }
        }
        
        int t = max_index;
        
        while(t >= 0)
        {
            ans.push_back(nums[t]);
            t = previous_index[t];
        }
        
        return ans;
    }
};