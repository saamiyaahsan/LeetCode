class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<pair<int,int>>st;
        
        vector<int>ans;
        
        for(int i=temperatures.size()-1;i>=0;i--)
        {
            if(i == temperatures.size()-1 || st.empty() == true)
            {
                ans.push_back(0);
                st.push({temperatures[i],i});
            }
            
            else
            {
                if(st.empty() == true)
                {
                    ans.push_back(0);
                    st.push({temperatures[i],i});
                }
                
                else
                {
                    while(st.empty() != true && st.top().first <= temperatures[i])
                    {
                        st.pop();
                    }
                    
                    if(st.empty() != true)
                    {
                        int day = st.top().second - i;
                        ans.push_back(day);
                        st.push({temperatures[i],i});
                    }
                    
                    else
                    {
                        ans.push_back(0);
                        st.push({temperatures[i],i});
                    }
                }
            }
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};