class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        
        bool S = false,T = false;
        
        string x = "";
        string y = "";
        string v = "";
        string w = "";
        
        int p,q;
        
        for(int i = 0;i<num1.size();i++)
        {
            if(i == 0 && num1[i] == '-'|| num1[i] >= '0' && num1[i] <= '9')
            {
                x.push_back(num1[i]);
            }
            
            else
            {
                p = i;
                break;
            }
        }
        
        for(int i = 0;i<num2.size();i++)
        {
            if(i == 0 && num2[i] == '-' || num2[i] >= '0' && num2[i] <= '9')
            {
                y.push_back(num2[i]);
            }
            
            else
            {
                q = i;
                break;
            }
        }
        
        
        int N1,N2,N3,N4;
        
        N1 = stoi(x);
        N2 = stoi(y);
        
      
        
        for(int i=p+1;i<num1.size();i++)
        {   
//             if(num1[i] == '+')
//             {
//                 continue;
//             }
            
//             if(num1[i] == '-')
//             {
//                 S = true;
//             }
            
            if(num1[i] >= '0' && num1[i] <= '9' || num1[i] == '-')
            {
                v.push_back(num1[i]);
            }
            
            else
            {
                break;
            }
        }
        
        for(int i=q+1;i<num2.size();i++)
        {
//             if(num2[i] == '+')
//             {
//                 continue;
//             }
            
//             if(num2[i] == '-')
//             {
//                 T = true;
//             }
            
            if(num2[i] >= '0' && num2[i] <= '9' || num2[i] == '-')
            {
                w.push_back(num2[i]);
            }
            
            else
            {
                break;
            }
        }
        
             
        N3 = stoi(v);
        N4 = stoi(w);
        
        if(S == true)
        {
            N3 = -N3;
        }
        
        if(T == true)
        {
            N4 = -N4;
        }
        
           // return x;
        int a,b,c,d;
        
        a = N1*N2 - (N3*N4);
        b = N1*N4 + N2*N3;
        
        string ans = to_string(a) + '+' + to_string(b) +'i';       
        
        return ans;
    }
};