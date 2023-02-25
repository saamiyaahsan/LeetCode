class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        
        if(k == 1 || k == 2)
        {
            return 1;
        }
        
        vector<int>ans;
        ans.push_back(1);
        ans.push_back(1);
        
        int res = 2;
        
        while(res <= k)
        {
            ans.push_back(res);
            
            int a = ans[ans.size()-1];
            int b = ans[ans.size()-2];
            
            res = a + b;
        }
        
        int i = ans.size()-1,c=0;
        
        while(k > 0)
        {
            while(i >= 0 && ans[i] > k)
            {
                i--;
            }
            
            k = k-ans[i];
            c++;
        }
        
        return c;
    }
};