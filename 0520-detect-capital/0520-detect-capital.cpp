class Solution {
public:
    bool detectCapitalUse(string word) {
     
     int i,c=0,k=0;   
     
     for(i=1;i<word.size();i++)   
     {
         if((word[i] >= 65) && (word[i] <= 90))
         {
             c++;
         }
         
         else
         {
             k++;
         }
     } 
        
        if((word[0] >= 65) && (word[0] <= 90))
         {
               c++;
         }
           
        if((c == word.size()) || (k == word.size()-1))
        {
            return true;
        }
           return false;
    }
};