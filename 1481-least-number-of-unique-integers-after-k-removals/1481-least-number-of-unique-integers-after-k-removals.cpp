class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        unordered_map<int,int>mp;
        
        vector<vector<int>>nums;
        
        int cnt = 0;
        
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        
        for(auto it : mp)
        {
            nums.push_back({it.second,it.first});
        }
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++)
        {
            int x = nums[i][0];
            
            while(x > 0 && k > 0)
            {
                x--;
                k--;
            }
            
            nums[i][0] = x;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i][0] > 0)
            {
                cnt++;
            }
        }
        
        return cnt;
    }
};