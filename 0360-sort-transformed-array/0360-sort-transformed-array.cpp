class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        
        long long p;
        
        for(int i=0;i<nums.size();i++)
        {
            p = (a*pow(nums[i],2)) + (b*nums[i]) + c;
            nums[i] = p;
        }
        
        sort(nums.begin(),nums.end());
        
        return nums;
    }
};