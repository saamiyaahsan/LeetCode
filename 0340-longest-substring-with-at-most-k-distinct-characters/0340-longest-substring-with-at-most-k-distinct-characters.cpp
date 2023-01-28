class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        unordered_map<char,int>mp;
        
        int ans = 0, j = -1;
        
        
        for(int i=0;i<s.size();i++)
        {
           mp[s[i]]++;
            
          while(mp.size() > k)
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