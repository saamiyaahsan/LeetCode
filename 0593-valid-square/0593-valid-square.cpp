class Solution {
public:
    
    int helper(vector<int>& a,vector<int>& b)
    {
        int p;
        
        p = pow(abs(a[0]-b[0]),2) + pow(abs(a[1]-b[1]),2);
        
        return p;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
            
        set<int>st;
        
        st.insert(helper(p1,p2));
         st.insert(helper(p2,p3));
         st.insert(helper(p3,p4));
         st.insert(helper(p1,p4));
         st.insert(helper(p2,p4));
         st.insert(helper(p1,p3));
        
        if(st.size() == 2 && !st.count(0))
        {
            return true; 
        }
        
        
        return false;
    }
};