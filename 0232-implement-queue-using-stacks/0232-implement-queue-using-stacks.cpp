class MyQueue {
public:
    
    stack<int>st;
    stack<int>St;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        
        st.push(x);
        
    }
    
    int pop() {
        
        while(st.size() != 1)
        {
            St.push(st.top());
            st.pop();
        }
        
        int x = st.top();
        st.pop();
        
        while(St.empty() != true)
        {
            st.push(St.top());
            St.pop();
        }
        
        return x;
    }
    
    int peek() {
        
        while(st.size() > 1)
        {
            St.push(st.top());
            st.pop();
        }
        
        int x = st.top();
        st.pop();
        St.push(x);
        
        while(St.empty() != true)
        {
            st.push(St.top());
            St.pop();
        }
        
        return x;
    }
    
    bool empty() {
        
        if(st.empty() == true)
        {
            return true;
        }
        
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */