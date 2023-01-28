class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
       
        unordered_map<int,int>mp;
        
        int ans = 0;
        
        for(int i=0;i<candies.size();i++)
        {
            mp[candies[i]]++;
        }
        
        for(int i=0;i<k;i++)
        {
            mp[candies[i]]--;
            
            if(mp[candies[i]] == 0)
            {
                mp.erase(candies[i]);
            }
        }
        
        int p = mp.size();
        
        ans = max(ans,p);
        
        for(int i=k;i<candies.size();i++)
        {
            mp[candies[i-k]]++;
            mp[candies[i]]--;
            
            if(mp[candies[i]] == 0)
            {
                mp.erase(candies[i]);
            }
            
            p = mp.size();
            
            ans = max(ans,p);
        }
        
        return ans;
    }
};