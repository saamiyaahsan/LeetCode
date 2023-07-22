class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
     
        sort(nums.begin(),nums.end());
        
        set<vector<int>>st;
        
        vector<vector<int>>ans;
        
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int k = j+1;
                int l = nums.size()-1;
                
                while(k < l)
                {
                    long long sum;
                    long long p = nums[i];
                    long long q = nums[j];
                    long long r = nums[k];
                    long long s = nums[l];
                    sum = (long long) (p+q+r+s);
                    
                    if(sum == target)
                    {
                        st.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                    }
                    
                    else if(sum > target)
                    {
                        l--;
                    }
                    
                    else
                    {
                        k++;
                    }
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