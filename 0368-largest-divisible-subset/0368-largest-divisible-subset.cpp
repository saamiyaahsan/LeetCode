class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        vector<int>dp(nums.size(),1);
        vector<int>hash(nums.size());
        
        int last_index = 0,maxi=0;
        
        for(int i=0;i<nums.size();i++)
        {
            hash[i] = i;
            
            for(int j=0;j<i;j++)
            {
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            
            if(maxi < dp[i])
            {
                maxi = dp[i];
                last_index = i;
            }
        }
        
        vector<int>temp;
        
        temp.push_back(nums[last_index]);
        
        while(last_index != hash[last_index])
        {
              last_index = hash[last_index];      
            temp.push_back(nums[last_index]);
        }
        
        reverse(temp.begin(),temp.end());
        
        return temp;
    }
};