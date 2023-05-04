class Solution {
public:
    
    
    
    int evalRPN(vector<string>& tokens) {
       
        stack<int>st;
        
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
            {
                int num = stoi(tokens[i]);
                st.push(num);
            }
            
            else
            {
                if(tokens[i] == "+")
                {
                    int x = st.top();
                    st.pop();
                    int y = st.top();
                    st.pop();
                    int z = x + y;
                    st.push(z);
                }
                
                else if(tokens[i] == "-")
                {
                    int x = st.top();
                    st.pop();
                    int y = st.top();
                    st.pop();
                    int z = y - x;
                    st.push(z); 
                }
                
                else if(tokens[i] == "*")
                {
                    int x = st.top();
                    st.pop();
                    int y = st.top();
                    st.pop();
                    int z = x*y;
                    st.push(z); 
                }
                
                else
                {
                    int x = st.top();
                    st.pop();
                    int y = st.top();
                    st.pop();
                    int z = y/x;
                    st.push(z);  
                }
            }
        }
        
        return st.top();
    }
};