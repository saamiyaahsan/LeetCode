class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>>ans;
        set<vector<int>>st;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++)
        {
            int j = i+1;
            int k = nums.size()-1;
            
            while(j < k)
            {
                long long sum;
                long long p = nums[i];
                long long q = nums[j];
                long long r = nums[k];
                
                sum = p + q + r;
                
                if(sum == 0)
                {
                    st.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                
                else if(sum > 0)
                {
                    k--;
                }
                
                else
                {
                    j++;
                }
            }
        }
        
        for(auto it : st)
        {
            ans.push_back(it);
        }
        
        return ans;
    }
};