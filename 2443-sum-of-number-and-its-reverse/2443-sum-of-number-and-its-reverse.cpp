class Solution {
public:
    
    int reverse(int num)
    {
        int q=0,rev=0;
        
        while(num != 0)
        {
            q = num%10;
            rev = rev*10 + q;
            num = num/10;
        }
        
        return rev;
    }
    
    bool sumOfNumberAndReverse(int num) {
        
        if(num == 0)
        {
            return true;
        }
        for(int i=0;i<num;i++)
        {
            int p = i;
            
            int x = reverse(i);
            
            if(p + x == num)
            {
                return true;
            }
        }
        
        return false;
    }
};