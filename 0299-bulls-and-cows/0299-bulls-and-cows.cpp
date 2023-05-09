class Solution {
public:
    string getHint(string secret, string guess) {
        
        string ans = "";
        
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        
        int cnt = 0,CNT = 0;
        
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i] == guess[i])
            {
                cnt++;
            }
            
            else
            {
                m1[secret[i]]++;
                m2[guess[i]]++;
            }
        }
        
        for(auto it : m2)
        {
           if(m1.find(it.first) != m1.end())
           {
               CNT = CNT + min(m1[it.first],it.second);
           }
        }
        
        ans = to_string(cnt) + 'A' + to_string(CNT) + 'B';
        
        return ans;
    }
};