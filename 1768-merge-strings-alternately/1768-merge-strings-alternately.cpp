class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string t;
        
        int i=0,j=0,c=0;
        
        while(i < word1.size() && j < word2.size())
        {
            if(c % 2 == 0)
            {
                t = t + word1[i];
                i++;
                c++;
            }
            
            else
            {
                t = t + word2[j];
                j++;
                c++;
            }
        }
        
        while(i < word1.size())
        {
            t = t + word1[i];
            i++;
        }
        
        while(j < word2.size())
        {
            t = t + word2[j];
            j++;
        }
        
        return t;
    }
};