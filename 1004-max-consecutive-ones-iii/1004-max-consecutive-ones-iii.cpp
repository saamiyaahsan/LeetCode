class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int ans = 0;
        int i,j;
        j = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 0)
            {
                k--;
            }
            
            while(k < 0)
            {
                if(nums[j] == 0)
                {
                    k++;
                }
                j++;
            }
            
            ans = max(ans,i-j+1);
        }
        
        // ans = max(ans,i-j);
        
        return ans;
    }
};