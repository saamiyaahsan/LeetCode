class Solution {
public:
    
    int rev(int x)
    {
        int p,q=0;
        
        while(x != 0)
        {
           p = x%10; 
           x = x/10;
           q = q*10 + p;  
        }
        
        return q;
    }
    
    int countNicePairs(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        unordered_map<long long,long long> mp;
        
        vector<int> res;
        
        int i,j,c=0,p;
        long long mod = 1e9+7;
        long long ans=0;
        
        for(i=0;i<nums.size();i++)
        {
            p = nums[i] - rev(nums[i]);
            res.push_back(p);
        }
        
        sort(res.begin(),res.end());
        
         for(i=0;i<res.size();i++)
         {
             mp[res[i]]++;
         }
        
         for(auto it : mp)
         {
              ans = ans + (it.second*1ll)*((it.second)*1ll-1)/2;
             ans = ans%mod;
              
         } 
        return ans;
    }
};