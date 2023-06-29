class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<banned.size();i++)
        {
            mp[banned[i]] = 1;
        }
        
        int sum = 0,cnt=0;
        
        for(int i=1;i<=n;i++)
        {
            if(mp.find(i) == mp.end())
            {
                sum = sum + i;
                
                if(sum <= maxSum)
                {
                    cnt++;
                }
                
                else
                {
                    break;
                }
            }
        }
        
        return cnt;
    }
};