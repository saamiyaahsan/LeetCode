class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        
        unordered_map<long long,long long>mp;
        
        long long currsum = 0 , maxlen = 0;
    
        for(int i=0;i<nums.size();i++)
        {
            currsum = currsum + nums[i];
            
            if(currsum == k)
            {
                maxlen = i+1;
            }
            
            if(mp.find(currsum-k) != mp.end())
            {
                maxlen = max(maxlen,i-mp[currsum-k]);
            }
            
            if(mp.find(currsum) == mp.end())
            {
                mp[currsum] = i;
            }
        }
        
        return maxlen;
        
    }
};