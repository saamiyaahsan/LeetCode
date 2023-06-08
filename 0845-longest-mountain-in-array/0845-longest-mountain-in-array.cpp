class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        vector<int>dp1(arr.size(),1);
        vector<int>dp2(arr.size(),1);
        
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i] > arr[i-1])
            {
                dp1[i] = 1 + dp1[i-1];
            }
        }
        
        for(int i=arr.size()-2;i>=0;i--)
        {
            if(arr[i] > arr[i+1])
            {
                dp2[i] = 1 + dp2[i+1];
            }
        }
        
        int ans = 0;
        for(int i=0;i<arr.size();i++)
        {
            if(dp1[i] > 1 & dp2[i] > 1)
            {
                ans = max(ans,dp1[i]+dp2[i]-1);
            }
        }
        
        return ans;
    }
};