class Solution {
public:
    int addMinimum(string word) {
        
        int i=0,cnt=0,n=word.size(),ans=0;
        
        while(i < n)
        {
            cnt = 0;
            
            if(word[i] == 'a')
            {
                cnt++;
                i++;
            }
            
            if(word[i] == 'b' && i < n)
            {
                cnt++;
                i++;
            }
            
            if(word[i] == 'c' && i < n)
            {
                cnt++;
                i++;
            }
            
            ans = ans + (3-cnt);
        }
        
        return ans;
    }
};