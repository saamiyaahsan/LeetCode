class Solution {
public:
    long long numberOfSubstrings(string s) {
        
        unordered_map<char,long long>mp;
        
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        
        long long ans = 0;
        
        for(auto it : mp)
        {
            ans = ans + (it.second)*(it.second-1)/2;
        }
        
        // ab individual bhi count karo kyuki every character is satisfying the conditon
        
        ans = ans + s.size();
        
        return ans;
    }
};