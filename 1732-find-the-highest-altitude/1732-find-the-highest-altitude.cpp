class Solution {
public: 
    int largestAltitude(vector<int>& gain) {
        
       int sum = 0,ans = 0;
        
       for(int i=0;i<gain.size();i++) 
       {
           sum = sum + gain[i];
           ans = max(ans,sum);
       } 
        
        return ans;
    }   
};       