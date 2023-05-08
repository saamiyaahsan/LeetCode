class Solution {
public:
    int countHomogenous(string s) {
        
        if(s.size() == 1)
        {
            return 1;
        }
        
        long long cnt = 1,ans = 0;
        
        char p;
        
        p = s[0];
        
        for(int i=1;i<s.size();i++)
        {
            if(s[i] == p)
            {
                cnt++;
            }
            
            else
            {
                long long y = cnt*(cnt+1)/2;
                y = y % 1000000007;
                
                ans = ans + y;
                cnt = 1;
                p = s[i];
            }
        }
        
        ans = ans + cnt*(cnt+1)/2;
        
        return ans % 1000000007;
    }
};