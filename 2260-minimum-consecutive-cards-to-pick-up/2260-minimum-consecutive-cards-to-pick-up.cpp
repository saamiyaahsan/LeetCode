class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        map<int,vector<int>>mp;
        
        for(int i=0;i<cards.size();i++)
        {
            mp[cards[i]].push_back(i);
        }
        
        int result = INT_MAX;
        
         for(auto it : mp)
         {
             vector<int>ans = it.second;
             sort(ans.begin(),ans.end());
             
             if(ans.size() == 1)
             {
                 continue;
             }
             
             else
             {
                 int p = INT_MAX;
                 
                 for(int i=1;i<ans.size();i++)
                 {
                     p = min(p,ans[i]-ans[i-1]);
                 }
                 result = min(result,p+1);
             }
         }
        
        if(result == INT_MAX)
        {
            return -1;
        }
        return result;
    }
};