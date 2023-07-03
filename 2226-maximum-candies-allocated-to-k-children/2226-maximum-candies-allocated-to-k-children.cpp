class Solution {
public:
    
    bool func(vector<int>candies,long long k,long long c)
    {
        long long sum = 0;
        
        for(int i=0;i<candies.size();i++)
        {
            sum = sum + (candies[i]/c);
        }
        
        return (sum >= k);
    }
    int maximumCandies(vector<int>& candies, long long k) {
        
        int maxi = 0;
        
        for(int i=0;i<candies.size();i++)
        {
            maxi = max(maxi,candies[i]);
        }
        
        int ans = 0;
        
//         for(int i=1;i<=maxi;i++)
//         {
//             if(func(candies,k,i))
//             {
//                 ans = i;
//             }
//         }
        
          int low = 1,high = maxi; 
          
          while(low <= high)
          {
              int mid = (low + high)/2;
              
              if(func(candies,k,mid))
              {
                  ans = mid;
                  low = mid + 1;
              }
              
              else
              {
                  high = mid - 1;
              }
          }
        
        return ans;
    }
};