class Solution {
public:
    string removeStars(string s) {
       
        stack<char>st;
        
        string t;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i] != '*')
            {   
                st.push(s[i]);   
            }
            
            else
            {
               if(st.empty() != true)
               {
                   st.pop();       
               }
                
            }
        }
        
        while(st.empty() != true)
        {
            t.push_back(st.top());
            st.pop();
        }
        
        reverse(t.begin(),t.end());
        
        return t;
    }
};