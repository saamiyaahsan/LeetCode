class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
      
        int i,j;
        
        vector<int> res;
        vector<int> ans;
        
        for(i=0;i<n;i++)
        {
           ans.push_back(nums[i]);    
        }
        
        for(i=n;i<nums.size();i++)
        {
            res.push_back(nums[i]);
        }
        
        nums.clear();
        
        i=0;
        j=0;
        
        while(i < ans.size() || j < res.size())
        {   
            if(nums.size()%2 == 0)
            {
                nums.push_back(ans[i]);
                i++;
            }
            
            else
            {
                nums.push_back(res[j]);
                j++;
            }
        }
        
        return nums;
    }
};