class Solution {
public:
    int minimumLength(string s) {
        
        int i=0,j=s.size()-1;
        
        while(i < j)
        {
            int c = s[i];
            
            if(s[i] != s[j])
            {
                return j-i+1;
            }
            
            else
            {
                while(i < s.size() && s[i] == c)
                {
                    i++;
                }
                
                while(j >= 0 && s[j] == c)
                {
                    j--;
                }
            }
        }
        
        if(i == j)
        {
            return 1;
        }
        
        return 0;
    }
};