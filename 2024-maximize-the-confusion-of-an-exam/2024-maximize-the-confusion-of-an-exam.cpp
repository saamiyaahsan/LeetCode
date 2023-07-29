class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int n = answerKey.size();
        
        int max_freq = 0,j = 0,ans = 0;
        
        vector<int>arr(26,0);
        
        for(int i=0;i<n;i++)
        {
            arr[answerKey[i]-'A']++;
            max_freq = max(max_freq,arr[answerKey[i]-'A']);
            
            while(i-j+1-max_freq > k)
            {
                arr[answerKey[j]-'A']--;
                j++;
            }
            
            ans = max(ans,i-j+1);
        }
        
        return ans;
    }
};