class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     
        int i,j,maxLength=0;
        while(i<s.size())
        {  
            vector<bool> visited(256);
            j=i;
            while(j<s.size() && (visited[s[j]] == false))
            {
                maxLength = max(maxLength,(j-i+1));
                visited[s[j]] = true;
                j++;
            }
            
            visited[s[i]] = false;
            i++;
        }
        
        return maxLength;
    }
};