class Solution {
public:
    string getHint(string secret, string guess) {
        
        int cnt = 0;
        
        map<int,int>mp1;
        map<int,int>mp2;
        
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i] == guess[i])
            {
                cnt++;
            }
            
            else
            {
                mp1[secret[i]-'0']++;
                mp2[guess[i]-'0']++;
            }
        }
        
        int c = 0;
        
        for(auto it : mp1)
        {
            if(mp2.find(it.first) != mp2.end())
            {
                c = c + min(it.second,mp2[it.first]);
            }
        }
        
        string ans = "";
        
        ans = to_string(cnt) + "A" + to_string(c) + "B";
        
        return ans;
    }
};