class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
       int ans=INT_MIN,sum=0,total=0,prev=nums[0],best=nums[0],res=0; 
        
       for(int i=0;i<nums.size();i++) 
       {
          total = total + nums[i];   
       }
        
       for(int i=0;i<nums.size();i++)   
       {
           sum = sum + nums[i];
           ans = max(ans,sum);
           
           if(sum < 0)
           {
               sum = 0;
           }
       }
    
       
       for(int i=1;i<nums.size();i++)    
       {
           res = total - prev;
           prev = prev + nums[i];
           ans = max(ans,res + best);
           best = max(best,prev);
       }
        
        return ans;
    }
};