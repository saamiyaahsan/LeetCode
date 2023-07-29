class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        unordered_map<int,int>mp;
        
        int cnt = 0,sum = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum = sum + nums[i];
            
            if(sum == goal)
            {
                cnt++;
            }
            
            if(mp.find(sum-goal) != mp.end())
            {
                cnt = cnt + mp[sum-goal];
            }
            
            mp[sum]++;
        }
        
        return cnt;
    }
};