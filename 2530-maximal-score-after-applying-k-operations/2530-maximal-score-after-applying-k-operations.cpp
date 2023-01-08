class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        priority_queue<int>pq;
        
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        
        long long sum = 0;
        
        while(pq.empty() != true && k>0)
        {
            long long res = pq.top();
            pq.pop();
            
            sum = sum + res;
            
            long double y = res;
            y = ceil(y/3);
            res = y;
            
            pq.push(res);
            k--;
        }
        
        return sum;
    }
};