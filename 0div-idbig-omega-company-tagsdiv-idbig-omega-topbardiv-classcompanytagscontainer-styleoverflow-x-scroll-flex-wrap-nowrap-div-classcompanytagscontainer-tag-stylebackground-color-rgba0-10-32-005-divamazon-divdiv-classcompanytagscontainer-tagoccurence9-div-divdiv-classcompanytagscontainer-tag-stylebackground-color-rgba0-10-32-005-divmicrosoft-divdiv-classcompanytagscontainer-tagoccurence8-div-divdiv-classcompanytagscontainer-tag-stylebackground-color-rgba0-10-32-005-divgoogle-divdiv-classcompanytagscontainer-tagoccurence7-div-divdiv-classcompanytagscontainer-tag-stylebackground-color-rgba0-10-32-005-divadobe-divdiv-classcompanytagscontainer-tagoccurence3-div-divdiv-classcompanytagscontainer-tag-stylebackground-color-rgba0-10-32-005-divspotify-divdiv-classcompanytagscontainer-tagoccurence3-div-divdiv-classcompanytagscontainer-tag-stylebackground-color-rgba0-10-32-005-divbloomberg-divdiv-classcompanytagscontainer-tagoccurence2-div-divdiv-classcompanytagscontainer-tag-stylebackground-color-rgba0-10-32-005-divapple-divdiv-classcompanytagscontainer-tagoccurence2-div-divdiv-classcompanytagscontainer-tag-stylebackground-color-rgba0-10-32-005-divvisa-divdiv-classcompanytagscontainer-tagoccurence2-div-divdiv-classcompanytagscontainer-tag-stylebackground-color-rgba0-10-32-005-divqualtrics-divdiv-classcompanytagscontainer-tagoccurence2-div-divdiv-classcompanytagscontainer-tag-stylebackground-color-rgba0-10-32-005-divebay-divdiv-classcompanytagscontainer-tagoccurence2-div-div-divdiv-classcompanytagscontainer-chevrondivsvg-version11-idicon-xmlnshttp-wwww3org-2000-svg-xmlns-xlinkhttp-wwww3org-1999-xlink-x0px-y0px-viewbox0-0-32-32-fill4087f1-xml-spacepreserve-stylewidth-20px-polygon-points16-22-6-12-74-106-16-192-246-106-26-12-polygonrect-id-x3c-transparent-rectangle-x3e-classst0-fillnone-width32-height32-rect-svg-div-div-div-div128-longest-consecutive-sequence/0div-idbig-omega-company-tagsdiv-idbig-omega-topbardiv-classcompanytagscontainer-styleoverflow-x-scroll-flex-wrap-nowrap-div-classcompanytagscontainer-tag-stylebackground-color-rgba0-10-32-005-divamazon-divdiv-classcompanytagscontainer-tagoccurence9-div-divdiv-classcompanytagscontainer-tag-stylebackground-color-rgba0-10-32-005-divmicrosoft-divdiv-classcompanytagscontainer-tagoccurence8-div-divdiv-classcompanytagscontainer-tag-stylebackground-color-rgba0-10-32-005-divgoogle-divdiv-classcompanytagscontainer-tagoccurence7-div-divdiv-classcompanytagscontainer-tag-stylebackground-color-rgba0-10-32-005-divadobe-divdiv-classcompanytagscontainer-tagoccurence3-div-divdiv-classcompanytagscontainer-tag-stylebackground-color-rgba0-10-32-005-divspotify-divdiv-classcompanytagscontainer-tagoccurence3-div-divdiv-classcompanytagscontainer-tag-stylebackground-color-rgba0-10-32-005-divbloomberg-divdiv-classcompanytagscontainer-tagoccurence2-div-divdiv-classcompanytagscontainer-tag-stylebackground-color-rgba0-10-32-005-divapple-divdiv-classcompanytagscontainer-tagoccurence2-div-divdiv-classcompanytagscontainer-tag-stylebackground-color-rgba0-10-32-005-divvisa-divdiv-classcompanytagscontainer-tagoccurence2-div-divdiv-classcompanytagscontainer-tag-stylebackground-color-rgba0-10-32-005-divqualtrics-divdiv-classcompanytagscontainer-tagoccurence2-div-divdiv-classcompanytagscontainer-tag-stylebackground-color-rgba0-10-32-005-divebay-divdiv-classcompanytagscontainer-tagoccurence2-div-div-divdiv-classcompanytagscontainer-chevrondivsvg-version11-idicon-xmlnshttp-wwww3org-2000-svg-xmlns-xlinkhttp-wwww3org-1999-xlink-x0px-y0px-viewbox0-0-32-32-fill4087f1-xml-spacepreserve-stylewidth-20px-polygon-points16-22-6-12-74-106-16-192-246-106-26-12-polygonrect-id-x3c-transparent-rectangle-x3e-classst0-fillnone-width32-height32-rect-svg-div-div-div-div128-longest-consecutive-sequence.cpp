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
        
        int ans = 0,cnt = 1;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] == nums[i-1] + 1)
            {
                cnt++;
            }
            
            else
            {
                ans = max(ans,cnt);
                cnt = 1;
            }
        }
        
        ans = max(ans,cnt);
        
        return ans;
    }
};