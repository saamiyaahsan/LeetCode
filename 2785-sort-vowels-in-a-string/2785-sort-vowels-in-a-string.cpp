class Solution {
public:
    
    bool helper(char c)
    {
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c =='i' || c == 'o' || c == 'u')
        {
            return true;
        }
        
        return false;
    }
    string sortVowels(string s) {
        
        string res;
        
        for(int i=0;i<s.size();i++)
        {
            if(helper(s[i]))
            {
                res.push_back(s[i]);
            }
        }
        
        sort(res.begin(),res.end());
        
        int k = 0;
        
        for(int i=0;i<s.size();i++)
        {
            if(helper(s[i]))
            {
                s[i] = res[k];
                k++;
            }
        }
        
        return s;
    }
};