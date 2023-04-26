class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        
        //priority_queue<int>pq max heap
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        
        while(k != 0)
        {
            int x = pq.top();
            pq.pop();
            x++;
            k--;
            pq.push(x);
        }
        
        long long ans = 1;
        
        while(pq.empty() != true)
        {
            int x = pq.top();
            pq.pop();
            ans = ans % 1000000007;
            ans = ans*x;
        }
        
        ans = ans % 1000000007;
        
        return ans;
    }
};