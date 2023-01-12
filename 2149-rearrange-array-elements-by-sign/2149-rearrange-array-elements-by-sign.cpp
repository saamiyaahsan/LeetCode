class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int i,j;
        
        vector<int> res;
        vector<int> ans;
        vector<int> val;
        
        for(i=0;i<nums.size();i++)
        {
            if(nums[i] > pivot)
            {
                res.push_back(nums[i]);
            }
            
            else if(nums[i] == pivot)
            {
                val.push_back(nums[i]);
            }
            
            else
            {
                ans.push_back(nums[i]);
            }
        }
        
        nums.clear();
        i=0;
        
        while(i<ans.size())
        {
            nums.push_back(ans[i]);
            i++;
        }
        
        i = 0;
        
        while(i<val.size())
        {
            nums.push_back(val[i]);
            i++;
        }
        
        i=0;
        
        while(i<res.size())
        {
            nums.push_back(res[i]);
            i++;
        }
        
        return nums;
    }
};