class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        
        vector<vector<int>>ans;
        
        for(int i=0;i<nums1.size();i++)
        {
            mp1[nums1[i]]++;
        }
        
        for(int i=0;i<nums2.size();i++)
        {
            mp2[nums2[i]]++;
        }
        
        vector<int>v;
        vector<int>w;
        
        for(auto it : mp1)
        {
            if(mp2[it.first] == 0)
            {
                v.push_back(it.first);
            }
        }
        
        for(auto it : mp2)
        {
            if(mp1[it.first] == 0)
            {
                w.push_back(it.first);
            }
        }
        
        ans.push_back(v);
        ans.push_back(w);
        
        return ans;
    }
};