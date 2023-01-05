class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int i,j,ans = 0;
        
        vector<int>visited(3,0);
        
        j = 0;
        
        for(i=0;i<s.size();i++)
        {
            visited[s[i]-'a']++;
            
            while(visited[0] && visited[1] && visited[2])
            {
                visited[s[j]-'a']--;
                
                ans = ans + s.size()-i;
                
                j++;
            }
        }
        
        return ans;
    }
};