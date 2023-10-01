class Solution {
public:
    string reverseWords(string s) {
        
        vector<string>ans;
        
        string t = "";
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i] != ' ')
            {
                t.push_back(s[i]);
            }
            
            else
            {
                reverse(t.begin(),t.end());
                ans.push_back(t);
                t.clear();
            }
        }
        
        if(t.empty() != true)
        {
             reverse(t.begin(),t.end());
                ans.push_back(t);
        }
        
        string res = "";
        
        for(int i=0;i<ans.size()-1;i++)
        {
            res = res + ans[i] + " ";
        }
        
        res = res + ans[ans.size()-1];
        
        return res;
    }
};