class Solution {
public:
    vector<int> evenOddBit(int n) {
        
        string s;
        
        vector<int>res;
        
        while(n != 0)
        {
            s.push_back(n%2 + '0');
            n = n/2;
        }
        
        int c = 0,cnt = 0;
        
        // reverse(s.begin(),s.end());
        
        for(int i=0;i<s.size();i++)
        {
            if(i % 2 == 0 && s[i] == 1 + '0')
            {
                c++;
            }
            
            else if(i % 2 == 1 && s[i] == 1 + '0')
            {
                cnt++;
            }
        }
        
        res.push_back(c);
        res.push_back(cnt);
        
        return res;
    }
};