class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int>pq;
        
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        
        int ans;
        
        while(k != 0 && pq.empty() != true)
        {
            int x = pq.top();
            ans = x;
            pq.pop();
            k--;
        }
        
        return ans;
    }
};