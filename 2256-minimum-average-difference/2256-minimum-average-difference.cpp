class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        vector<int>prefix;
        
        long long sum = 0,p=0,cnt1,cnt2,ans=INT_MAX,avg1,avg2,res;
        
        for(int i=0;i<nums.size();i++)
        {
            sum = sum + nums[i];
        }
        
        cnt1 = nums.size();
        cnt2 = 0;
        
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(cnt2 == 0)
            {
                avg1 = sum/cnt1;
                
                if(ans >= avg1)
                {
                    ans = avg1;
                    res = i;
                }
            }
            
            else
            {
                avg1 = sum/cnt1;
                avg2 = p/cnt2;
                
                int newVal = abs(avg1-avg2);
                
                if(ans >= newVal)
                {
                    ans = newVal;
                    res = i;
                }
            }
            
            sum = sum - nums[i];
            p = p + nums[i];
            cnt1--;
            cnt2++;
        }
        
        return res;
    }
};