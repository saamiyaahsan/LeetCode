class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
            priority_queue<int>pq;
           
           long long sum = 0;
           
           for(int i=0;i<nums.size();i++)
           {
               pq.push(nums[i]);
           }
           
           while(pq.empty() != true && k != 0)
           {
               long long x = pq.top();
               pq.pop();
               k--;
               sum = sum + x;
               
               long double y = x;
                y = ceil(y/3);
                x = y;
               pq.push(x);
           }
        
           return sum;
    }
};