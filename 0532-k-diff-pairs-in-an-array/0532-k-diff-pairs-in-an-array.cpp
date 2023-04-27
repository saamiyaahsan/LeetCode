class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        set<vector<int>>st;
        
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(abs(nums[i]-nums[j]) == k)
                {
                    st.insert({nums[i],nums[j]});
                }
            }
        }
        
        return st.size();
    }
};