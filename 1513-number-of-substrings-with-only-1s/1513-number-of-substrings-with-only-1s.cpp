class Solution {
public:
    int numSub(string s) {
        
        long long cnt = 0,ans = 0;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '1')
            {
                cnt++;
            }
            
            else
            {
                ans = ans % 1000000007;
                
                long long p = cnt*(cnt+1)/2;
                
                p = p % 1000000007;
                
                ans = ans + p % 1000000007;
                cnt = 0;
            }
        }
        
        ans = ans + cnt*(cnt + 1)/2;
        
        return ans % 1000000007;
    }
};