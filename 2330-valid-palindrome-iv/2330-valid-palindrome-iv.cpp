class Solution {
public:
    bool makePalindrome(string s) {
        
        int i,j,cnt=0;
        
        i=0;
        j=s.size()-1;
        
        while(i < j)
        {
            if(s[i] != s[j])
            {
                cnt++;
            }
            
            i++;
            j--;
        }
        
        if(cnt <= 2)
        {
            return true;
        }
        
        return false;
    }
};