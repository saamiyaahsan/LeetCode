class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        vector<int>ans(60,0);
        
        int res = 0;
        
        for(auto it : time)
        {
            res = res + ans[(540-it)%60];
            ans[it%60]++;
        }
        
        return res;
    }
};