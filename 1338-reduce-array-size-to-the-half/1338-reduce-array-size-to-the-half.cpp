class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        
        priority_queue<pair<int,int>>pq;
        
        for(auto it : mp)
        {
            pq.push({it.second,it.first});
        }
        
        int n = arr.size();
        int cnt = 0;
        
        while(pq.empty() != true)
        {
            auto x = pq.top();
            pq.pop();
            
            n = n - x.first;
            cnt++;
            
            if(n <= arr.size()/2)
            {
                return cnt;
            }
        }
        
        return cnt;
        
    }
};