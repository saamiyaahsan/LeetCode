class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<vector<int>>ans;
        
        priority_queue<pair<int,pair<int,int>>>pq;
        
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                int sum = nums1[i] + nums2[j];
                
                if(pq.size() < k)
                {
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                
                else if(pq.size() == k && sum < pq.top().first)
                {
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                
                else
                {
                    break;
                }
            }
        }
        
        while(pq.empty() != true)
        {
            auto x = pq.top().second;
            pq.pop();
            ans.push_back({x.first,x.second});
        }
        
        return ans;
    }
};