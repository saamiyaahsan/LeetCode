class Solution {
public:
    int countOdds(int low, int high) {
        
        int i,c=0;
        
        for(i=low;i <= high;i++)
        {
            if(i % 2 != 0)
            {
                c++;
            }
        }
        
        return c;
    }
};