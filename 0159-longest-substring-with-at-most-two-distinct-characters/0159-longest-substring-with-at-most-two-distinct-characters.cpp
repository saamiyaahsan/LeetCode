class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        unordered_map<char,int>mp;
        
        int ans = 0,j = -1;
        
        for(int i=0;i<s.size();i++)
        {
           mp[s[i]]++;
           
           while(mp.size() > 2)
           {
               j++;
               
               if(--mp[s[j]] == 0)
               {
                   mp.erase(s[j]);
               }
               
           }
            
             ans = max(ans,i-j);
            
        }
        
        return ans;
    }
};