class Solution {
public: 
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
          
        map<string,int>mp;
        
        for(int i=0;i<=s.size()-minSize;i++)
        {
            mp[s.substr(i,minSize)]++;
        }
        
        int ans = 0;
        
        set<char>st;
        
        for(auto it : mp)
        {
            set<char>st;
            for(int i=0;i<it.first.size();i++)
            {
                st.insert(it.first[i]);
            }
            if(st.size() <= maxLetters)
            {
               ans = max(ans,it.second);        
            }
           
        }
        
        return ans;
    }
};