class Solution {
public:
    int longestContinuousSubstring(string s) {
        
        int cnt = 1,ans = 0;
        
        for(int i=1;i<s.size();i++)
        {
            if(s[i] == s[i-1] + 1)
            {
                cnt++;
            }
            
            else
            {
                ans = max(ans,cnt);
                cnt = 1;
            }
        }
        
        ans = max(ans,cnt);
        
        return ans;
    }
};