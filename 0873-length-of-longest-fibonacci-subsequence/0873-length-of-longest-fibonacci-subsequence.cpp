class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        
        int N = arr.size();
        
        int ans = 0;
        
        unordered_set<int>st(arr.begin(),arr.end());
        
        for(int i=0;i<N;++i)
        {
            for(int j=i+1;j<N;++j)
            {
                int x = arr[i];
                int y = arr[j];
                int z = arr[i] + arr[j];
                int length = 2;
                
                while(st.find(z) != st.end())
                {
                    x = y;
                    y = z;
                    z = x+y;
                    length++;
                }
                
               ans = max(ans,length);
            }
        }
        
        if(ans >= 3)
        {
            return ans;
        }
        
        return 0;
    }
};