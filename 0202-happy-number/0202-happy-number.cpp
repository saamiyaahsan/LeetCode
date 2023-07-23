class Solution {
public:
    
    
    int solve(int n)
    {
        int num = 0;
        
        while(n != 0)
        {
            num = num + pow(n%10,2);
            n = n/10;
        }
        
        return num;
    }
    bool isHappy(int n) {
        
        unordered_set<int>st;
        
        while(n != 1 && !st.count(n))
        {
            st.insert(n);
            int num = solve(n);
            n = num;
        }
        
        if(n == 1)
        {
            return true;
        }
        
        return false;
    }
};