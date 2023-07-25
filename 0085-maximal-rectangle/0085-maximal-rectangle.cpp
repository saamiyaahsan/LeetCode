class Solution {
public:
    
    int MaximumAreaOfHistogram(vector<int>& heights)
    {
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
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        vector<int>v;
        
        for(int i=0;i < matrix[0].size();i++)
        {
            v.push_back(matrix[0][i] - '0');
        }
        
        int mx = MaximumAreaOfHistogram(v);
        
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j] == '0')
                {
                    v[j] = 0;
                }
                
                else
                {
                    v[j] = v[j] + matrix[i][j] - '0';
                }
            }
            
            mx = max(mx,MaximumAreaOfHistogram(v));
        }
        
        return mx;
    }
};