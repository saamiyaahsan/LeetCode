class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int cnt = 0,c = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 0)
            {
                cnt++;
            }
            
            else if(nums[i] < 0)
            {
                c++;
            }
        }
        
        if(cnt > 0)
        {
            return 0;
        }
        
        if(c % 2 == 1)
        {
            return -1;
        }
        
        return 1;
    }
};