class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int>ans; // smallest to left
        vector<int>v; // smallest to right
        
        stack<pair<int,int>>st;
        
        for(int i=0;i<heights.size();i++)
        {
            if(st.empty() == true)
            {
                ans.push_back(-1);
            }
            
            else
            {
                while(st.empty() != true && st.top().first >= heights[i])
                {
                    st.pop();
                }
                
                if(st.empty() != true)
                {
                    ans.push_back(st.top().second);
                }
                
                else
                {
                    ans.push_back(-1);
                }
            }
            
            st.push({heights[i],i});
        }
        
        while(st.empty() != true)
        {
            st.pop();
        }
        
        for(int i=heights.size()-1;i>=0;i--)
        {
            if(st.empty() == true)
            {
                v.push_back(heights.size());
            }
            
            else
            {
                while(st.empty() != true && st.top().first >= heights[i])
                {
                    st.pop();
                }
                
                if(st.empty() != true)
                {
                    v.push_back(st.top().second);
                }
                
                else
                {
                    v.push_back(heights.size());
                }
            }
            
            st.push({heights[i],i});
        }
        
        reverse(v.begin(),v.end());
        
        int Ans = 0;
        
        for(int i=0;i<heights.size();i++)
        {
            Ans = max((v[i]-ans[i]-1)*heights[i],Ans);
        }
        
        return Ans;
    }
};