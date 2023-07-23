class CustomStack {
public:
    
    stack<int>st;
    
    int Stacksize;
    
    CustomStack(int maxSize) {
        
        Stacksize = maxSize;
    }
    
    void push(int x) {
        
        if(st.size() < Stacksize)
        {
            st.push(x);
        }
    }
    
    int pop() {
        
        if(st.empty() != true)
        {
            int p = st.top();
            st.pop();
            return p;
        }
        
        return -1;
    }
    
    void increment(int k, int val) {
        
        vector<int>ans;
        
        while(st.empty() != true)
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        if(ans.size() < k)
        {
            for(int i=0;i<ans.size();i++)
            {
                int p = ans[i];
                p = p + val;
                ans[i] = p;
            }
        }
        
        else
        {
            for(int i=0;i<k;i++)
            {
                int p = ans[i];
                 p = p + val;
                ans[i] = p;
            }
        }
        
        // reverse(ans.begin(),ans.end());
        
        for(auto it : ans)
        {
            st.push(it);
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */