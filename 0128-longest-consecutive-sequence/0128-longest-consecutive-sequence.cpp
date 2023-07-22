class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0)
        {
            return 0;
        }
        
        set<int>st;
        
        for(auto it : nums)
        {
            st.insert(it);
        }
        
        nums.clear();
        
        for(auto it : st)
        {
            nums.push_back(it);
        }
        
        sort(nums.begin(),nums.end());
        
        int ans = 0,len = 1;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] == nums[i-1] + 1)
            {
                len++;
            }
            
            else
            {
                ans = max(ans,len);
                len = 1;
            }
        }
        
        ans = max(ans,len);
        
        return ans;
    }
};