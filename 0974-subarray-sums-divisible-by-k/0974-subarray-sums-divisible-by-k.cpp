class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       
        map<int,int>mp; 
        
        int sum = 0,ans = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum = sum + nums[i];
            mp[(sum%k + k)%k]++;
            
        }
        
        for(int i=0;i<k;i++)
        {
            if(mp[i] > 1)
            {
                ans = ans + (mp[i])*(mp[i]-1)/2;
            }
        }
        
        ans = ans + mp[0];
        
        return ans;
        }
};