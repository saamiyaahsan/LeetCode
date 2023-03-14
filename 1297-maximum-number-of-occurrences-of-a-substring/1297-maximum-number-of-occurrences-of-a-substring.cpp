class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        
        map<string,int>mp;
        
        for(int i=0;i<=s.size()-minSize;i++)
        {
            mp[s.substr(i,minSize)]++;
        }
        
        int ans = 0;
        
        for(auto it : mp)
        {
            set<char> subs(begin(it.first),end(it.first));
            if(subs.size() <= maxLetters)
            {
               ans = max(ans,it.second);        
            }
           
        }
        
        return ans;
    }
};