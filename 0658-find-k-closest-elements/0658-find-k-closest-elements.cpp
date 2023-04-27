class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>res;
        
        for(int i=0;i<arr.size();i++)
        {
            int dist = abs(arr[i]-x);
            pq.push({dist,arr[i]});
        }
        
        while(pq.empty() != true && k != 0)
        {
            auto x = pq.top();
            pq.pop();
            k--;
            res.push_back(x.second);
        }
        
        sort(res.begin(),res.end());
        
        return res;
    }
};