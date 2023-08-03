class Solution {
public:
    
    void helper(string digits,int index,string p,vector<string>& res,unordered_map<int,string>& mp)
    {
//         if(index > digits.size())
//         {
//             return;
//         }
        
        if(index == digits.size())
        {
            res.push_back(p);
            return;
        }
        
        string x = mp[digits[index]-'0'];
        
        for(int i=0;i<x.size();i++)
        {
            p.push_back(x[i]);
            helper(digits,index+1,p,res,mp);
            p.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
        unordered_map<int,string>mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        
        string p;
        vector<string>res;
        
        if(digits.size() == 0)
        {
            return res;
        }
        int index = 0;
        helper(digits,index,p,res,mp);
        
        return res;
    }
};