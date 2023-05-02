class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        unordered_map<int,int>mp;
        
        int res = INT_MAX,ans = 0;
        
        for(int i = 0;i < cards.size();i++)
        {
            if(mp.find(cards[i]) != mp.end())
            {
                ans = i - mp[cards[i]] + 1;
                res = min(res,ans);
            }
            
            mp[cards[i]] = i;
        }
        
        if(res == INT_MAX)
        {
            return -1;
        }
        return res;
    }
};