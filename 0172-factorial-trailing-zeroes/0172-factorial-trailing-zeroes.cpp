class Solution {
public:
    int trailingZeroes(int n) 
    {
        int ans = 0,p;
        
        while(n >= 5)
        {
            p = n/5;
            ans = ans + p;
            n = n/5;
        }
        
        return ans;
    }
};