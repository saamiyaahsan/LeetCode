class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        
        long long t = k;
        long long sum = t*(t+1)/2; // sum of first k natural numbers;
        
        set<int>st;
        
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }
        
        nums.clear();
        
        for(auto it : st)
        {
            nums.push_back(it);
        }
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] <= k)
            {
                sum = sum - nums[i];
                sum = sum + (k + 1); // k tak already add ho chuka hai 
                k++;
            }
            
            else
            {
                break;
            }
        }
        
        return sum;
    }
};