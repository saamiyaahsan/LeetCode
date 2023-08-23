class Solution {
public:
    int trailingZeroes(int n) {
        
        long long cnt = 0;
        
        for(int i=5;n/i>=1;i*5)
        {
            cnt = cnt + (n/i);
            n = n/i;
        }
        
        return cnt;
    }
};