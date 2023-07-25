class MinStack {
public:
    
    stack<int>st;
    stack<int>St;
    
    MinStack() {
        
    }
    
    void push(int val) {
        
        st.push(val);
    
        if(St.empty() == true || St.top() >= val)
        {
            St.push(val);
        }
    }
    
    void pop() {
        
        int x;
        
        if(st.empty() != true)
        {
           x = st.top();
           st.pop();
        }
        
        if(x == St.top() && St.empty() != true)
        {
            St.pop();
        }
    }
    
    int top() {
        
        int x = st.top();
        
        return x;
    }
    
    int getMin() {
        
        return St.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */