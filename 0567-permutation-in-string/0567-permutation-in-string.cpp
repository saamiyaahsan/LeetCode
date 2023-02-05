class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int>window(26,0);
        vector<int>ans(26,0);
        
        if(s2.size() < s1.size())
        {
            return false;
        }
        for(int i=0;i<s1.size();i++)
        {
            window[s2[i]-'a']++;
            ans[s1[i]-'a']++;
        }
         
         if(ans == window)
         {
            return true;   
         } 
         
        for(int i=s1.size();i<s2.size();i++)
        {
            window[s2[i-s1.size()]-'a']--;
            window[s2[i]-'a']++;
            
            if(ans == window)
            {
                return true;
            }
        }
        
        return false;
    }
};