class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int cost = 0,ans=0;
        
        int j = 0;
        
        for(int i=0;i<s.size();i++)
        {
            cost = cost + abs(s[i]-t[i]);
            
            while(cost > maxCost)
            {
                cost = cost - abs(s[j]-t[j]);
                j++;
            }
            
            ans = max(ans,i-j+1);
        }
        
        return ans;
    }
};