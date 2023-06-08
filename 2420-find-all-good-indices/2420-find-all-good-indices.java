class Solution {
    public List<Integer> goodIndices(int[] nums, int k) {
        
        if(nums.length < 2 * k + 1)
       {
           return new ArrayList<>();
       }
        
        int dp_ni[] = new int[nums.length];
        dp_ni[0] = 1;
        for(int i = 1;i < nums.length;i++){
            if(nums[i] <= nums[i - 1]) dp_ni[i] = dp_ni[i - 1] + 1;
            else dp_ni[i] = 1;
        }
        
        int dp_nd[] = new int[nums.length];
        dp_nd[nums.length - 1] = 1;
        for(int i = nums.length - 2;i >= 0;--i){
            if(nums[i] <= nums[i + 1]) dp_nd[i] = dp_nd[i + 1] + 1;
            else dp_nd[i] = 1;
        }
        
        List<Integer> ans = new ArrayList<>();
        for(int i = k;i < nums.length - k;i++){
            if(dp_ni[i - 1] >= k && dp_nd[i + 1] >= k) ans.add(i);
        }
        return ans;
        
       
    }
}