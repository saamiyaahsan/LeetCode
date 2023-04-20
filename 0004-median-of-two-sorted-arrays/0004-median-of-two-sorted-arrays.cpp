class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        double ans;
        
        vector<int>nums3;
        
        int i=0,j=0;
        
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] <= nums2[j])
            {
                nums3.push_back(nums1[i]);
                i++;
            }
            
            else
            {
                nums3.push_back(nums2[j]);
                j++;
            }
        }
        
        while(i < nums1.size())
        {
            nums3.push_back(nums1[i]);
            i++;
        }
        
        while(j < nums2.size())
        {
            nums3.push_back(nums2[j]);
            j++;
        }
        
        int n = nums3.size();
        
        if(n % 2 == 1)
        {
            ans = nums3[(nums3.size()-1)/2];
            return ans;
        }
        
        ans = (nums3[(nums3.size()-1)/2] + nums3[(nums3.size()+1)/2]);
        ans = ans/2;
        return ans;
    }
};