class Solution {
public:
    int lengthOfLongestSubstring(string s) {
          
        int i,j,ans = 0;
        
        i = 0;
        j = 0;
        
        while(i < s.size())
        {
            unordered_map<char,int>mp;
            j = i;
            while(j < s.size() && mp.find(s[j]) == mp.end())
            {
                    mp[s[j]]++;
                    ans = max(ans,j-i+1);
                    j++;
                
            }
            
            mp[s[i]]--;
            
            if(mp[s[i]] == 0)
            {
                mp.erase(s[i]);
            }
            i++;
        }
        
        return ans;
    }
};