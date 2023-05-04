class Solution {
public:
    int maximumSwap(int num) {
        
        string p = "";
        string q = "";
        
        int ans;
        
        q = to_string(num);
        p = to_string(num);
        
        sort(p.rbegin(),p.rend());
        
        for(int i=0;i<p.size();i++)
        {
            if(p[i] != q[i])
            {
                int k;
                
                for(int j=i+1;j<p.size();j++)
                {
                    if(q[j] == p[i])
                    {
                        k = j;
                    }
                }
                
              swap(q[k],q[i]);
              ans = stoi(q);
             return ans;
            }
        }
        
        ans = num;
        
        return ans;
    }
};