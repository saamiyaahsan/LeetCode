class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        
        unordered_set<double>st;
        
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }
        
        int ans = 1;
        int curr = 1;
        
        for(int i=0;i<nums.size();i++)
        {
            curr = 1;
            
            double val = (double) nums[i];
            val = sqrt(val);
            
            while(st.find(val) != st.end())
            {
                curr++;
                val = sqrt(val);
            }
            
            ans = max(ans,curr);
        }
        
        if(ans == 1)
        {
            return -1;
        }
        
        return ans;
    }
};