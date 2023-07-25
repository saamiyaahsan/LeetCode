class Solution {
public:
    int trap(vector<int>& height) {
        
        vector<int>mxl;
        vector<int>mxr;
        
        int p = INT_MIN;
        
        int ans = 0;
        
        for(int i=0;i<height.size();i++)
        {
            p = max(p,height[i]);
            mxl.push_back(p);
        }
        
        p = INT_MIN;
        
        for(int i=height.size()-1;i>=0;i--)
        {
            p = max(p,height[i]);
            mxr.push_back(p);
        }
        
        reverse(mxr.begin(),mxr.end());
        
        for(int i=0;i<height.size();i++)
        {
            ans = ans + min(mxr[i],mxl[i]) - height[i];
        }
        
        return ans;
    }
};