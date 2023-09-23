class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        
        int ans = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            long long x = i,cnt = 0;
            
            while(x != 0)
            {
                int p = x % 2;
                  
                if(p == 1)
                {
                    cnt++;
                }
                
                x = x/2;
            }
            
            if(cnt == k)
            {
                ans = ans + nums[i];
            }
            
            cnt = 0;
        }
        
        return ans;
    }
};