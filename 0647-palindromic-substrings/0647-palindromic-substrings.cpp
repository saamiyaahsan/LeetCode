class Solution {
public:
    int countSubstrings(string s) {
        
        int cnt = 0;
        
        for(int i=0;i<s.size();i++)
        {
            string p = "";
            
            for(int j=i;j<s.size();j++)
            {
                // string p = s.substr(i,j);
                p.push_back(s[j]);
                string t = p;
                reverse(t.begin(),t.end());
                
                if(p == t)
                {
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};