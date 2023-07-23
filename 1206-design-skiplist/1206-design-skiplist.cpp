class Skiplist {
public:
    
    map<int,int>mp;
    
    Skiplist() {
        
    }
    
    bool search(int target) {
        
        if(mp[target] > 0)
        {
            return true;
        }
         
        return false;
    }
    
    void add(int num) {
        
        mp[num]++;
    }
    
    bool erase(int num) {
        
        if(mp[num] > 0)
        {
            mp[num]--;
            return true;
        }
        
        return false;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */