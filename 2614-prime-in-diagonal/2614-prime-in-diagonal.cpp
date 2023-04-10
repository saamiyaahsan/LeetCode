class Solution {
public:
    
    bool isPrime(int num)
    {
        if(num < 2)
        {
            return false;
        }
        
        for(int i=2;i<=sqrt(num);i++)
        {
            if(num % i == 0)
            {
                return false;
            }
        }
        
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        
        vector<int>res;
        
        for(int i=0;i<nums.size();i++)
        {
            res.push_back(nums[i][i]);
        }
        
        int k = nums.size()-1;
        
        for(int i=0;i<nums.size();i++)
        {
            res.push_back(nums[i][k]);
            k--;
        }
        
        int ans = 0;
        
        for(int i=0;i<res.size();i++)
        {
            if(isPrime(res[i]) == true)
            {
                ans = max(ans,res[i]);
            }
        }
        
        return ans;
    }
};