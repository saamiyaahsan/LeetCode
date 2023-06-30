class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int prod = 1,P = 1,ans;
        
        vector<int>res;
        vector<int>ANS;
        for(int i=0;i<nums.size()-1;i++)
        {
            P = P*nums[i];
        }
        
        for(int i=nums.size()-1;i>0;i--)
        {
            prod = prod*nums[i];
            res.push_back(prod);
        }
        
        prod = 1;
        
        reverse(res.begin(),res.end());
        
        for(int i=0;i<nums.size()-1;i++)
        {
            ans = res[i]*prod;
            ANS.push_back(ans);
            prod = prod*nums[i];
        }
        
        ANS.push_back(P);
        
        return ANS;
    }
};