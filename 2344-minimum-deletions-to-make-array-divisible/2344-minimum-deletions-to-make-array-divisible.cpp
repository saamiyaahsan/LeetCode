class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        sort(numsDivide.begin(),numsDivide.end());
        
        sort(nums.begin(),nums.end());
        
        int GCD = numsDivide[0];
        
        for(int i=1;i<numsDivide.size();i++)
        {
            GCD = __gcd(GCD,numsDivide[i]);
        }
        
        int cnt = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(GCD % nums[i] == 0)
            {
                return cnt;
            }
            
            else
            {
                cnt++;
            }
        }
        
        if(cnt == nums.size())
        {
            return -1;
        }
        return cnt;
    }
};