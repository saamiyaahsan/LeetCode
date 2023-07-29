class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int i=0,j=0,ans=0;
        
        map<char,int>mp;
        
        while(i < s.size())
        {
            j = i;
            
            while(j < s.size() && mp.find(s[j]) == mp.end())
            {
               mp[s[j]]++;
                  ans = max(ans,j-i+1); 
               j++;
            }
            
            // ans = max(ans,j-i+1);
            mp.clear();
            i++;
        }
        
        return ans;
    }
};