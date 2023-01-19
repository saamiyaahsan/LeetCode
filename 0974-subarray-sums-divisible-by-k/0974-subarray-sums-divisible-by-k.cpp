class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        
        int prefixSum = 0,remainder,ans = 0;
        
        mp[prefixSum % k] = 1;
        
        for(int i=0;i<nums.size();i++)
        {
            prefixSum = prefixSum + nums[i];
            
            remainder = ((prefixSum % k) + k) % k;
            
            if(mp.find(remainder) != mp.end())
            {
                ans = ans + mp[remainder];
            }
            
            mp[remainder]++;
        }
        
        return ans;
    }
};