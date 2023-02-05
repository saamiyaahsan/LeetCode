class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int>res;
        
        if(s.size() < p.size())
        {
            return res;
        }
        
        vector<int>ans(26,0);
        vector<int>window(26,0);
        
        for(int i=0;i<p.size();i++)
        {
           ans[p[i]-'a']++;
           window[s[i]-'a']++; 
        }
        
        if(ans == window)
        {
            res.push_back(0);
        }
        for(int i=p.size();i<s.size();i++)
        {
           window[s[i-p.size()]-'a']--; 
           window[s[i]-'a']++;
            
           if(ans == window)
           {
               res.push_back(i-p.size()+1);
           }
        }
        
        return res;
    }
};