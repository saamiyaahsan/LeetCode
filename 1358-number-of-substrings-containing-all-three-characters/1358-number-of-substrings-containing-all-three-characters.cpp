class Solution {
public:
    
    int helper(string s,int K)
    {
         map<char,int>mp;
        int j = 0,ans = 0;
        
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            
            while(mp.size() > K)
            {
                mp[s[j]]--;
                
                if(mp[s[j]] == 0)
                {
                    mp.erase(s[j]);
                }
                
                j++;
            }
            
            ans = ans + (i-j+1);
        }
        
        return ans;  
    }
    int numberOfSubstrings(string s) {
        
        int ans ;
      
        ans = helper(s,3) - helper(s,2);
        
        return ans;
    }
};