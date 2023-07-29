class Solution {
public:
    
    vector<int>res;
    
    Solution(vector<int>& nums) {
        
        res = nums;
    
    }
    
    int pick(int target) {
       
        vector<int>ans;
        
        for(int i=0;i<res.size();i++)
        {
            if(res[i] == target)
            {
                ans.push_back(i);
            }
        }
        
        int Result = ans[rand() % ans.size()];
     
        return Result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */