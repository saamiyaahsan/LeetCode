class Solution {
public:
    int characterReplacement(string s, int k) {
        
        vector<int>arr(26,0);
        
        int ans = 0,max_freq = 0,j = 0;
        
        for(int i=0;i<s.size();i++)
        {
            arr[s[i]-'A']++;
            max_freq = max(max_freq,arr[s[i]-'A']);
            
            while(i-j+1-max_freq > k)
            {
                arr[s[j]-'A']--;
                j++;
            }
            
            ans = max(ans,i-j+1);
        }
        
        return ans;
    }
};