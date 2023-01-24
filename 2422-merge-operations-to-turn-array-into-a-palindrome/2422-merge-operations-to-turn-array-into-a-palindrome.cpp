class Solution {
public:
    int minimumOperations(vector<int>& nums) {
     
        int i,j,cnt=0;
        
        i=0;
        j=nums.size()-1;
        
        vector<long long>newNum(nums.size());
        
        for(int i=0;i<nums.size();i++)
        {
            newNum[i] = nums[i];
        }
        while(i<j)
        {
            if(newNum[i] == newNum[j])
            {
                i++;
                j--;
            }
            
            else if(newNum[i] > newNum[j])
            {
                newNum[j-1] = newNum[j-1] + newNum[j];
                j--;
                cnt++;
            }
            
            else
            {
                newNum[i+1] = newNum[i+1] + newNum[i];
                i++;
                cnt++;
            }
        }
        
        return cnt;
    }
};