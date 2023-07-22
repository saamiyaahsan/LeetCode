class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<char>st1;
        stack<char>st2;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i] != '#')
            {
                st1.push(s[i]);
            }
            
            else
            {
                if(st1.empty() != true)
                {
                    st1.pop();
                }
            }
        }
        
        for(int i=0;i<t.size();i++)
        {
            if(t[i] != '#')
            {
                st2.push(t[i]);
            }
            
            else
            {
                if(st2.empty() != true)
                {
                    st2.pop();
                }
            }
        }
        
        s.clear();
        t.clear();
        
        while(st1.empty() != true)
        {
            s.push_back(st1.top());
            st1.pop();
        }
        
          while(st2.empty() != true)
         {
            t.push_back(st2.top());
            st2.pop();
         }
        
        if(s == t)
        {
            return true;
        }
        
        return false;
    }
};