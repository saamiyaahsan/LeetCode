class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        
        vector<vector<int>>res;
        
        for(int i=0;i<matches.size();i++)
        {
            mp1[matches[i][0]]++;
            mp2[matches[i][1]]++;
        }
         
        vector<int>v; 
        vector<int>w;
        
        for(auto it : mp2)
        {
            if(it.second == 1)
            {
                w.push_back(it.first);
            }
        }
        
        for(auto it : mp1)
        {
            if(mp2[it.first] == 0)
            {
                v.push_back(it.first);
            }
        }
        
        sort(v.begin(),v.end());
        sort(w.begin(),w.end());
        
        res.push_back(v);
        res.push_back(w);
        
        return res;
    }
};