class DataStream {
public:
    
    int value;
    int k;
    int count = 0;
    
    DataStream(int value, int k) {
        
        this->value = value;
        this->k = k;
    }
    
    bool consec(int num) {
        
        if(value == num)
        {
            count++;
        }
        
        else
        {
            count = 0;
        }
        
        if(count >= k)
        {
            return true;
        }
        
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */