class Solution {
public:
    
    bool ishelper(char x)
    {
        if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
        {
            return true;
        }
        
        return false;
    }
    string reverseVowels(string s) {
        
        int i,j;
        
        i=0;
        j=s.size()-1;
        
        while(i < j)
        {
            if(ishelper(s[i]) && ishelper(s[j]))
            {
                swap(s[i],s[j]);
                i++;
                j--;
            }
            
            else if(ishelper(s[i]))
            {
                j--;
            }
            
            else if(ishelper(s[j]))
            {
                i++;
            }
            
            else
            {
                i++;
                j--;
            }
        }
        
        return s;
    }
};