class Solution {
public:
    double myPow(double x,long long n) {
        
        if(n == 0)
        {
            return 1;
        }
        
        if(n < 0)
        {
            return myPow(1/x,long(-1*n));
        }
        
        double p = myPow(x,n/2);
        
        if(n % 2 == 0)
        {
            return p*p;
        }
        
        return p*p*x;
    }
};