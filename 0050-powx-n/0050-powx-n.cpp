class Solution {
public:
    double myPow(double x,long long n) {
        
        if(n == 0)
        {
           return 1;    
        }
        
        if(n < 0)
        {
            double y = (double)(1/x);
            return myPow(y,(long)(-1*n));
        }
        
        double res = myPow(x,n/2);
        
        if(n % 2 == 0)
        {
            return res*res;
        }
        
        return res*res*x;
    }
};