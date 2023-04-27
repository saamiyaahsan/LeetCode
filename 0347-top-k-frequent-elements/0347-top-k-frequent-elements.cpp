class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>>pq;
        
        vector<int>res;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto it : mp)
        {
            pq.push({it.second,it.first});
        }
        
        while(pq.empty() != true && k != 0)
        {
            auto x = pq.top();
            pq.pop();
            k--;
            res.push_back(x.second);
        }
        
        return res;
    }
};