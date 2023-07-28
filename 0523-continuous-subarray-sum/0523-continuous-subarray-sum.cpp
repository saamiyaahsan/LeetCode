class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       
        unordered_map<int,long long>mp;
        
        long long sum = 0,max_len = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum = sum + nums[i];
            
            long long rem = (sum % k + k) % k;
            
            if(rem == 0)
            {
                max_len = i+1;
            }
            
            else if(mp.find(rem) == mp.end())
            {
                mp[rem] = i;
            }
            
            else
            {
                max_len = max(max_len,i-mp[rem]);
            }
        }
        
        if(max_len >= 2)
        {
            return true;
        }
        
        return false;
    }
};