class Solution {
public:
    
    void helper(string s,int pos,string p,set<string>& ans)
    {
        if(pos > s.size())
        {
            return;
        }
        
        if(pos == s.size())
        {
            ans.insert(p);
            return;
        }
        
        p.push_back(s[pos]);
        helper(s,pos+1,p,ans);
        p.pop_back();
        
        if(s[pos] >= 'A' && s[pos] <= 'Z')
        {
            s[pos] = s[pos] + 32;
            p.push_back(s[pos]);
            helper(s,pos+1,p,ans);
            p.pop_back();
        }
        
         if(s[pos] >= 'a' && s[pos] <= 'z')
        {
            s[pos] = s[pos] - 32;
            p.push_back(s[pos]);
            helper(s,pos+1,p,ans);
            p.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        
        string p;
        set<string>ans;
        
        vector<string>res;
        
        helper(s,0,p,ans);
        
        for(auto it : ans)
        {
           res.push_back(it);    
        }
        
        return res;
    }
};