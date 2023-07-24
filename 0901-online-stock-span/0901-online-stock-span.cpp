class StockSpanner {
public:
  
    stack<pair<int,int>>st;
    StockSpanner() {
             st.push({INT_MAX,0});
    }
    
    int next(int price) {
       
        int idx = st.top().second + 1;
        
        while(st.empty() != true && st.top().first <= price)
        {
            st.pop();
        }
        
        int ans;
        
        ans = idx - st.top().second;
        
        st.push({price,idx});
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */