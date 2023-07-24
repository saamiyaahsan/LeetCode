class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        vector<int>res;
        
        int size = nums.size();
        
        for(int i=0;i<nums.size();i++)
        {
            int element = -1;
            
            for(int j=(i+1)%size;j!=i;j=(j+1)%size)
            {
                if(nums[i] < nums[j])
                {
                    element = nums[j];
                    break;
                }
            }
            res.push_back(element);
        }
        
        return res;
    }
};