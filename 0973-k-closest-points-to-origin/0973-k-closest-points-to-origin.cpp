class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
     vector<vector<int>>ans;       
     
 priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        for(int i=0;i<points.size();i++)
        {
            int dist = pow(points[i][0],2) + pow(points[i][1],2);
            pq.push({dist,{points[i][0],points[i][1]}});
        }
        
        while(k != 0 && pq.empty() != true)
        {
            auto x = pq.top();
            pq.pop();
            k--;
            int p1 = x.second.first;
            int p2 = x.second.second;
            ans.push_back({p1,p2});
        }
        
        return ans;
    }
};