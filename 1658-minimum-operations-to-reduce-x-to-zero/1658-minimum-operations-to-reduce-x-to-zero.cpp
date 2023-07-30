class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int Totalsum = 0,sum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            Totalsum = Totalsum + nums[i];
        }
        
        if(Totalsum == x)
        {
            return nums.size();
        }
        int RequiredSum = Totalsum - x,max_len = 0;
        
        map<int,int>mp;
        
        for(int i=0;i<nums.size();i++)
        {
            sum = sum + nums[i];
            
            if(sum == RequiredSum)
            {
                max_len = i + 1;
            }
            
            if(mp.find(sum) == mp.end())
            {
                mp[sum] = i;
            }
            
            if(mp.find(sum-RequiredSum) != mp.end())
            {
                max_len = max(max_len,i-mp[sum-RequiredSum]);
            }
        }
        
        if(max_len == 0)
        {
            return -1;
        }
        
        return nums.size()-max_len;
    }
};