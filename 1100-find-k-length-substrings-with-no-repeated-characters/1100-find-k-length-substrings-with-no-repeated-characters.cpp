class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        
        unordered_map<int,int>mp;
        
        if(k > s.size())
        {
            return 0;
        }
        for(int i=0;i<k;i++)
        {
            mp[s[i]]++;
        }
        
        int cnt = 0;
        
        if(mp.size() == k)
        {
            cnt++;
        }
        
        for(int i=k;i<s.size();i++)
        {
            mp[s[i-k]]--;
            mp[s[i]]++;
            
            if(mp[s[i-k]] == 0)
            {
                mp.erase(s[i-k]);
            }
            
            if(mp.size() == k)
            {
                cnt++;
            }
        }
        
        return cnt;
    }
};