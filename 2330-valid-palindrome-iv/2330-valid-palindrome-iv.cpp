class Solution {
public:
    bool makePalindrome(string s) {
        
        int i=0,j=s.size()-1,cnt = 0;
        
        while(i < j)
        {
            if(s[i] != s[j])
            {
                cnt++;
                i++;
                j--;
            }
            
            else
            {
                i++;
                j--;
            }
        }
        
        if(cnt <= 2)
        {
            return true;
        }
        
        return false;
    }
};