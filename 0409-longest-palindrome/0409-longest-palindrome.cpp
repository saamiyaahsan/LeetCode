class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char,int>mp;
        
        int ans = 0,res = 0;
        
        for(int i=0;i<s.size();i++)
        { 
            mp[s[i]]++;
        }
        
        for(auto it : mp)
        {
            if(it.second % 2 == 0)
            {
                ans = ans + it.second;
            }
        }
        
        bool p = false;
        
        for(auto it : mp)
        {
            if(it.second % 2 == 1)
            {
                p = true;
                res = max(res,it.second);
            }
        }
        
        //ans = ans + res;
        
        for(auto it : mp)
        {
            if(it.second % 2 == 1)
            {
                ans = ans + (it.second - 1);
            }
        }
        
        if(p == true)
        {
            return ans+1;     
        }
       
        return ans;
        
    }
};