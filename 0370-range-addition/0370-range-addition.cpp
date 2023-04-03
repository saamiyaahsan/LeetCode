class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        
        vector<int>prefix(length,0);
        
        for(int i=0;i<updates.size();i++)
        {
            int x = updates[i][0];
            int y = updates[i][1];
            int z = updates[i][2];
            
            prefix[x] = prefix[x] + z;
            
            if(y < prefix.size()-1)
            {
                prefix[y+1] = prefix[y+1] - z;     
            }
        }
        
        vector<int>ans;
        
        int sum = 0;
        
        for(int i=0;i<prefix.size();i++)
        {
            sum = sum + prefix[i];
            ans.push_back(sum);
        }
        
        return ans;
    }
};