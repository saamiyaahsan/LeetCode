class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        map<int,int>mp;
        
        long long TotalSum = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]-i]++;
        }
        
        long long ans = 0 , cnt = 0;
        
        for(auto it : mp)
        {
            if(it.second > 1)
            {
                long long p = it.second;
                long long q = it.second - 1;
                ans = ans + p*q/2; // counting number of good pairs using nC2 formula
            }
        }
        
        TotalSum = TotalSum + (nums.size())*(nums.size()-1)/2;
        
        return TotalSum - ans;
    }
};