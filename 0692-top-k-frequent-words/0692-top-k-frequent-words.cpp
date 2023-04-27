class Solution {
public:
    
    static bool cmp(pair<string,int>& a,pair<string,int>& b)
    {
        if(a.second > b.second)
        {
            return true;
        }
        
        else if(a.second == b.second)
        {
            if(a.first < b.first)
            {
                return true;
            }
        }
        
        return false;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        vector<pair<string,int>>ans;
        unordered_map<string,int>mp;
        
        vector<string>res;
        
        for(int i=0;i<words.size();i++)
        {
            mp[words[i]]++;
        }
        
        for(auto it : mp)
        {
            ans.push_back({it.first,it.second});
        }
        
        sort(ans.begin(),ans.end(),cmp);
        
       // vector<string>res;
        
        for(int i=0;i<k;i++)
        {
            res.push_back(ans[i].first);
        }
        
        return res;
    }
};