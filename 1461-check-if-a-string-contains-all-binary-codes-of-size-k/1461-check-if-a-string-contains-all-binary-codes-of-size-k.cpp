class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        string t;
        
        if(k > s.size())
        {
            return false;
        }
        for(int i=0;i<k;i++)
        {
            t = t + s[i];
        }
        
        map<string,int>mp;
        
        mp[t]++;
        
        string p;
        
        for(int i=k;i<s.size();i++)
        {
            p = t.substr(1,t.size()-1);
            p = p + s[i];
            
            mp[p]++;
            
            t = p;
            
        }
        
        if(mp.size() == pow(2,k))
        {
            return true;
        }
        
        return false;
    }
};