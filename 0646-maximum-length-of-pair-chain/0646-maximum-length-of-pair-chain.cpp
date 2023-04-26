class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        for(int i=0;i<pairs.size();i++)
        {
            swap(pairs[i][0],pairs[i][1]);    
        }
        
        sort(pairs.begin(),pairs.end());
        
        for(int i=0;i<pairs.size();i++)
        {
            swap(pairs[i][0],pairs[i][1]);    
        }
        
        int i=0,cnt = 1;
        
        for(int j=1;j<pairs.size();j++)
        {
            if(pairs[i][1] < pairs[j][0])
            {
                cnt++;
                i = j;
            }
            
        }
        
        return cnt;
    }
};