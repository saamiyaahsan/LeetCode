class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        
        int ans = 0;
        
        map<int,int>mp;
        
        if(nums.size() < 4)
        {
            return 0;
        }
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int prod = nums[i]*nums[j];
                
                mp[prod]++;
            }
            
        }
        
        
        for(auto it : mp)
        {
            ans = ans  + 4*(it.second)*(it.second-1);
        }
        
        return ans;
    }
};