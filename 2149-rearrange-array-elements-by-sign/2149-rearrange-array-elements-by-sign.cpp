class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int>ans(nums.size(),0);
        
        int i=0,j=1;
        
        for(auto it : nums)
        {
            if(it > 0)
            {
                ans[i] = it;
                i = i + 2;
            }
            
            else
            {
                ans[j] = it;
                j = j + 2;
            }
        }
        
        return ans;
    }
};