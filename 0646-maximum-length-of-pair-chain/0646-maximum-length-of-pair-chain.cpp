class Solution {
public:
    
    static bool comp(vector<int>& a ,vector<int>& b)
    {
        if(a[1] < b[1])
        {
            return true;
        }
        
        return false;
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(),pairs.end(),comp);
        
        int p = pairs[0][1];
        
        int c = 1;
        
        for(int i=1;i<pairs.size();i++)
        {
            if(pairs[i][0] > p)
            {
                p = pairs[i][1];
                c++;
            }
        }
        
        return c;
    }
};