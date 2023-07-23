class MyStack {
public:
    
    queue<int>q;
    queue<int>Q;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        
        if(q.empty() != true)
        {
          while(q.size() != 1)
         {
            int x = q.front();
            Q.push(x);
            q.pop();
         }
        
          int x = q.front();
            q.pop();
          while(Q.empty() != true)
         {
            int x = Q.front();
            q.push(x);
            Q.pop();
         }  
         
       
          return x;      
        }
      
        return -1;
    }
    
    int top() {
        
       if(q.empty() != true)
       {
           int x = q.back();
           return x;
       }
        
        return -1;
    }
    
    bool empty() {
        
        if(q.empty() != true)
        {
            return false;
        }
        
        return true;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */