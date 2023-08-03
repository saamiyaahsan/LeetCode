class Solution {
public:
    
    void helper(int index,string digits,string p,map<int,string>& mp,vector<string>& ans)
    {
        if(index == digits.size())
        {
            ans.push_back(p);
            return;
        }
        
        string x = mp[digits[index]-'0'];
        
        for(int i=0;i<x.size();i++)
        {
            p.push_back(x[i]);
            helper(index+1,digits,p,mp,ans);
            p.pop_back();
        }
    
    }
    vector<string> letterCombinations(string digits) {
        
        map<int,string>mp;
        
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        
        vector<string>ans;
        
        if(digits.size() == 0)
        {
            return ans;
        }
        
        string p = "";
        
        helper(0,digits,p,mp,ans);
    
        return ans;
    }
};