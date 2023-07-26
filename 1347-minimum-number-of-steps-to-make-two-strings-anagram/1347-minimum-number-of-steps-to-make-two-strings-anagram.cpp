class Solution {
public:
    int minSteps(string s, string t) {
     
        vector<int>hash1(26,0);
        vector<int>hash2(26,0);
        
        for(int i=0;i<s.size();i++)
        {
            hash1[s[i]-'a']++;
            hash2[t[i]-'a']++;
        }
        
        int cnt = 0;
        
        for(int i=0;i<26;i++)
        {
            if(hash1[i] > hash2[i])
            {
                cnt = cnt + hash1[i] - hash2[i];
            }
        }
        
        return cnt;
    }
};