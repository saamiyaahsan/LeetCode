class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
         
        vector<int>temp;
        
        for(int i : nums)
        {
            auto lb = lower_bound(temp.begin(),temp.end(),i);
            
            if(lb == temp.end())
            {
                temp.push_back(i);     
            }
           
            else
            {
                *lb = i;     
            }
           
        }
        
        return temp.size()>=3;
    }
};