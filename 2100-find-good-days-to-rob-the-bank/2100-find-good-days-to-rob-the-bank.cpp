class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& nums, int time) {
        
          int n=nums.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        vector<int>ans;
        left[0]=1;
        right[n-1]=1;
        for(int i=1;i<n;i++){
            left[i]=(nums[i-1]>= nums[i]);
            left[i]+=left[i-1];
        }
        for(int i=n-2;i>=0;i--){
            right[i]=(nums[i+1]>= nums[i]);
            right[i]+=right[i+1];
        }
        for(int i=time;i+time<n;i++){
            if(left[i]-left[i-time]==right[i]-right[i+time]&&left[i]-left[i-time]==time )
                ans.push_back(i);
        }
        return ans;
        
    }
};