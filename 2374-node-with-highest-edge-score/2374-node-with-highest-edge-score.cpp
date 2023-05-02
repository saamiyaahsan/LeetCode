class Solution {
public:
    int edgeScore(vector<int>& edges) {
        
        map<int,vector<int>>mp;
        
        for(int i=0;i<edges.size();i++)
        {
            mp[edges[i]].push_back(i);
        }
        
        int ans = INT_MIN,p = 0;
        
        for(auto it : mp)
        {
            long long sum = 0;
            
            for(int i=0;i<it.second.size();i++)
            {
                sum = sum + it.second[i];
            }
            
            if(ans < sum)
            {
                ans = sum;
                p = it.first;
            }
        }
        
        return p;
    }
};