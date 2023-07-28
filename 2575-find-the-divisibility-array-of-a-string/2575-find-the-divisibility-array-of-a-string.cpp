class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
       
        vector<int>ans;
        
        long long num = 0;
        
        for(int i=0;i<word.size();i++)
        {
            num = num*10 + (word[i]-'0');
            num = num % m;
            if(num  == 0)
            {
                ans.push_back(1);
            }
            
            else
            {
                ans.push_back(0);
            }
        }
        
        return ans;
    }
};