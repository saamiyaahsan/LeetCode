class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
        map<int,int>mp;
        
        for(int i=1;i<=n;i++)
        {
            mp[i]++;
        }
        
        for(int i=0;i<banned.size();i++)
        {
            if(mp.find(banned[i]) != mp.end())
            {
                mp[banned[i]] = 0;
                mp.erase(banned[i]);
            }
        }
        
        int cnt = 0,sum = 0;
        
        for(auto it : mp)
        {
            sum = sum + it.first;
            
            if(sum <= maxSum)
            {
                    cnt++;
            }
            
            else
            {
                break;
            }
        }
        
        return cnt;
    }
};