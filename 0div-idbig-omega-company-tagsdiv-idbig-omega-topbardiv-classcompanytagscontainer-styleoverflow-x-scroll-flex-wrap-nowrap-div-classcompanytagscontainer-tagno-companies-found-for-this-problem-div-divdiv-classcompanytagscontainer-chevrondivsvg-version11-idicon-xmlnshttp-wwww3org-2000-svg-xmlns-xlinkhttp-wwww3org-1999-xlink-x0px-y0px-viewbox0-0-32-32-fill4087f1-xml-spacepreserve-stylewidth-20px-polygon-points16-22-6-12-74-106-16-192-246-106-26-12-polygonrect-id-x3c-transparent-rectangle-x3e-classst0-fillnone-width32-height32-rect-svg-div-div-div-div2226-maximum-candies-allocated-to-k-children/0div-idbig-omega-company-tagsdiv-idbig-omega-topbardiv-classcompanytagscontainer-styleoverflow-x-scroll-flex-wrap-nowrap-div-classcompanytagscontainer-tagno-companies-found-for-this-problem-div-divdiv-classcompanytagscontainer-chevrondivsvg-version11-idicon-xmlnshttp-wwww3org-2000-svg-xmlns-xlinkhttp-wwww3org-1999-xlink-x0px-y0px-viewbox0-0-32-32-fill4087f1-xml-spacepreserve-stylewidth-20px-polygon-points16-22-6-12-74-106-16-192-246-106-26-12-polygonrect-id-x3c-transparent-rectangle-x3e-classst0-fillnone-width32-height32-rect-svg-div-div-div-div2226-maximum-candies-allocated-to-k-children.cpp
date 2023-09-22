class Solution {
public:
    
    long long helper(vector<int>& candies,long long c)
    {
        long long sum = 0;
        
        for(int i=0;i<candies.size();i++)
        {
            sum = sum + (candies[i]/c);
        }
        
        return sum;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        
        int maxi = 0;
        
        for(int i=0;i<candies.size();i++)
        {
            maxi = max(maxi,candies[i]);
        }
        
        int low = 1,high = maxi,ans = 0;
        
        while(low <= high)
        {
            long long mid = (low + high)/2;
            
            if(helper(candies,mid) >= k)
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