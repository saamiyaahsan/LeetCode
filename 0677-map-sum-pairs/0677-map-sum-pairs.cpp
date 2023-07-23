class MapSum {
public:
    
    map<string,int>mp;
    
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        
        mp[key] = val;
    }
    
    int sum(string prefix) {
        
        int Sum = 0;
        
        for(auto it : mp)
        {
            string p = it.first;
            if(p.substr(0,prefix.size()) == prefix)
            {
                Sum = Sum + it.second;
            }
        }
        
        return Sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */