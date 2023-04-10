class Solution {
public:
    bool isValid(string s) {
        
//         stack<char>st;
        
//         for(auto c : s)
//         {
//             if(c == '(' || c == '{' || c == '[')
//             {
//                 st.push(c);
//             }
            
//             else
//             {
//                 if(st.empty() == true || (st.top() == '(' && c != ')') || (st.top() == '{' && c != '}') || (st.top() == '[' && c != ']'))
//                 {
//                     return false;
//                 }
                
//                 st.pop();
//             }
//         }
        
//         return st.empty();
        
        stack<char>st;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            
            else
            {
                if(st.empty() == true || st.top() == '(' && s[i] != ')' || st.top() == '{' && s[i] != '}' || st.top() == '[' && s[i] != ']')
                {
                    return false;      
                }
                
                st.pop();
            }
        }
        
        return st.empty();
        
    }
};