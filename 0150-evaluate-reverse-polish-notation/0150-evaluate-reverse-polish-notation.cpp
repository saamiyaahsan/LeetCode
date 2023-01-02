class Solution {
public:
    
    long helper(int a,int b,char op)
    {
        if(op == '+')
        {
            return a+b;
        }
        
        else if(op == '-')
        {
            return a-b;
        }
        
        else if(op == '*')
        {
            return (long)a*b;
        }
        
        else
        {
            return a/b;
        }
    }
    int evalRPN(vector<string>& tokens) {
        
        stack<long>st;
        
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i].size() == 1 && tokens[i][0] < 48)
            {
                int p = st.top();
                
                st.pop();
                
                int q = st.top();
                
                st.pop();
                
                string oper = tokens[i];
                
                long x = helper(q,p,oper[0]);
                
                st.push(x);
            }
            
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        
        return st.top();
    }
};