class MyCircularDeque {
public:
    
    queue<int>q1;
    queue<int>q2;
    int Size;
    
    MyCircularDeque(int k) {
        Size = k;
    }
    
    bool insertFront(int value) {
      
        if(q1.size() == Size)
        {
            return false;
        }
        
        while(q1.empty() != true)
        {
            q2.push(q1.front());
            q1.pop();
        }
        
        q1.push(value);
        
        while(q2.empty() != true)
        {
            q1.push(q2.front());
            q2.pop();
        }
        
        return true;
    }
    
    bool insertLast(int value) {
        
        if(q1.size() == Size)
        {
            return false;
        }
        
        q1.push(value);
        return true;
    }
    
    bool deleteFront() {
        
        if(q1.size() == 0)
        {
            return false;
        }
        
        q1.pop();
        
        return true;
    }
    
    bool deleteLast() {
        
        if(q1.size() == 0)
        {
            return false;
        }
        
        while(q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        
        q1.pop();
        
        while(q2.empty() != true)
        {
            q1.push(q2.front());
            q2.pop();
        }
        
        return true;
    }
    
    int getFront() {
        
        if(q1.size() == 0)
        {
            return -1;
        }
        
        return q1.front();
    }
    
    int getRear() {
        
        if(q1.size() == 0)
        {
            return -1;
        }
        
        return q1.back();
    }
    
    bool isEmpty() {
        
        if(q1.size() == 0)
        {
            return true;
        }
        
        return false;
    }
    
    bool isFull() {
        
        if(q1.size() == Size)
        {
            return true;
        }
        
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */