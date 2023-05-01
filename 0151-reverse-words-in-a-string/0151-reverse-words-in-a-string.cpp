class Solution {
public:
    string reverseWords(string s) {
        
        stack<string>st;
        
        string t;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i] != ' ')
            {
               t = t + s[i];       
            }
            
            else
            {
                if(t.empty() != true)
                {
                    st.push(t);     
                    t.clear();
                }
                
                else
                {
                    continue;
                }
            }
            
        }
        
        
        if(t.empty() != true)
        {
            st.push(t);
             t.clear();     
        }
       
        
        while(st.size() != 1)
        {
            auto x = st.top();
            st.pop();
            
            t = t + x + ' ';
        }
        
        t = t + st.top();
        
        return t;
    }
};