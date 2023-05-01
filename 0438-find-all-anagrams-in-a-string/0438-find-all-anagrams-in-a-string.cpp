class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int>res;
        
        vector<int>freq_s(26,0);
        vector<int>freq_p(26,0);
        
        if(s.size() < p.size())
        {
            return res;
        }
        
        for(int i=0;i<p.size();i++)
        {
            freq_p[p[i]-'a']++;
            freq_s[s[i]-'a']++;
        }
                   
         if(freq_p == freq_s)
        {
           res.push_back(0);
        }
                   
        for(int i=p.size();i<s.size();i++)
        {
            freq_s[s[i-p.size()]-'a']--;
            freq_s[s[i]-'a']++;
            
            if(freq_p == freq_s)
            {
                res.push_back(i-p.size()+1);
            }
        }
                       
        return res;
                   
    }
};