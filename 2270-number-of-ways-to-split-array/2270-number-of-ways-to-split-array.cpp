class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
         long long i,sum=0,p=0,c=0,ans=0;
        
        for(i=0;i<nums.size();i++)
        {
            sum = sum + nums[i];
        }
        
        for(i=0;i<nums.size()-1;i++)
        {
            p = p + nums[i];
            ans = sum-p;
            
            if(p >= ans)
            {
                c++;
            }
        }
        
        return c;
    }
};