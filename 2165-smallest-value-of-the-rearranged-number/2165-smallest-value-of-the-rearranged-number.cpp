class Solution {
public:
    long long smallestNumber(long long num) {
           long long res=0;
        
        vector<int>ans;
        
        if(num == 0)
        {
            return 0;
        }
        
        if(num < 0)
        {
            num = num*(-1);
            
            while(num != 0)
            {
                long long x = num % 10;
                ans.push_back(x);
                num = num/10;
            }
            
            sort(ans.rbegin(),ans.rend());
            
            for(int i=0;i<ans.size();i++)
            {
                res = res*10 + ans[i]; 
            }
            
            res = res*-1;
        }
        
        else
        {
            while(num != 0)
            {
                long long x = num % 10;
                ans.push_back(x);
                num = num/10;
            }
            
            sort(ans.begin(),ans.end());
            
            int a;
            
            for(int i=0;i<ans.size();i++)
            {
                if(ans[i] != 0)
                {
                    a = i;
                    break;
                }
            }
            
            res = res*10 + ans[a];
            
            for(int i=0;i<ans.size();i++)
            {
                if(i != a)
                {
                    res = res*10 + ans[i];
                }
            }
        }
        
        
        return res;
    }
};