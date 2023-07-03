class Solution {
public:
    
    int helper(vector<int>& nums,int divisor)
    {
        int sum = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum = sum + ceil((1.0*nums[i])/divisor);
        }
        
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        
      int low = 1;
      int high = *max_element(nums.begin(),nums.end());
      int ans = 0;  
        
      while(low <= high)  
      {
          int mid = (low + high)/2;
          int result = helper(nums,mid);
          
          if(result <= threshold)
          {
              ans = mid;
              high = mid-1;
          }
          
          else
          {
              low = mid + 1;
          }
      }
        
        return ans;
    }
};