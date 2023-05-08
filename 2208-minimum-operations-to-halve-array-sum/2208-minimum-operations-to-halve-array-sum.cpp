class Solution {
public:
    int halveArray(vector<int>& nums) {
       
        priority_queue<double>pq;
        double sum = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum = sum + nums[i];
            pq.push(nums[i]);
        }
        
        sum = sum/2;
        int cnt = 0;
        
        while(sum > 0)
        {
            double x = pq.top();
            pq.pop();
            
            pq.push(x/2);
            cnt++;
            sum = sum - x/2;
        }
        
        return cnt;
    }
};