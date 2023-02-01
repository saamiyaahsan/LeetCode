class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        int p = 0;
        
        for(int i=1;i<=str1.size();i++)
        {
            if(str1.size() % i == 0 && str2.size() % i == 0)
            {
                p = i;
            }
        }
        
        string str = "";
        
        if(str1 + str2 == str2 + str1)
        {
            str = str1.substr(0,p);
        }
        
        return str;
    }
};