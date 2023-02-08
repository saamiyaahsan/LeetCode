class Solution {
public:
    int jump(vector<int>& nums) {
        
        int pos = 0,destination = 0,cnt = 0;
         
        
        for(int i=0;i<nums.size()-1;i++)
        {
            destination = max(destination,i+nums[i]);
            
            if(pos == i)
            {
                pos = destination;
                cnt++;
            }
        }
        
        return cnt;
    }
};