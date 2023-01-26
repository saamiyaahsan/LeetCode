class Solution {
public:
    
    int cnt = 0;
    
    int Merge(vector<int>& nums,int start,int end)
    {
        int mid = (start+end)/2;
         
        int i,j;
         
        i = start;
        j = mid + 1;
        
        while(i <= mid && j <= end)
        {
            long long t = 2*(long(nums[j]));
            
            while(i<= mid && nums[i] <= t)
            {
                i++;
            }
            
            cnt = cnt + (mid-i+1);
            j++;
        }
        
        vector<int>temp;
        
        i = start;
        j = mid+1;
        
        while(i <= mid && j <= end)
        {
            if(nums[i] <= nums[j])
            {
                temp.push_back(nums[i]);
                i++;
            }
            
            else
            {
                temp.push_back(nums[j]);
                j++;
            }
        }
        
        while(i <= mid)
        {
            temp.push_back(nums[i]);
                i++;
        }
        
        while(j <= end)
        {
           temp.push_back(nums[j]);
           j++; 
        }
        
        int k = 0;
        
        for(int p = start ; p <= end ; p++)
        {
            nums[p] = temp[k];
            k++;
        }
        
        return cnt;
    }
    
    void ModifiedMergeSort(vector<int>& nums,int start,int end)
    {
        if(start >= end)
        {
            return;
        }
        
        int mid = (start + end)/2;
        
         ModifiedMergeSort(nums,start,mid);
         ModifiedMergeSort(nums,mid+1,end);
         Merge(nums,start,end);
    }
    
    int reversePairs(vector<int>& nums) {
        
        ModifiedMergeSort(nums,0,nums.size()-1);
        
        return cnt;
    }
};