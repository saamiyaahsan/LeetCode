class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        map<int,char>mp;
        
        for(int i=0;i<26;i++)
        {
            mp[i] = 'A' + i;
        }
        
        string t;
        
        while(columnNumber != 0)
        {
            if(columnNumber > 26)
            {
                int res = columnNumber % 26;
                
                if(res == 0)
                {
                    t.push_back(mp[25]);
                     columnNumber = columnNumber/26 - 1;
                }
                
                else
                {
                    t.push_back(mp[res-1]);     
                     columnNumber = columnNumber/26;
                }
                
            }
            
            else
            {
                t.push_back(mp[columnNumber-1]);
                break;
            }
        }
        
        reverse(t.begin(),t.end());
        
        return t;
    }
};