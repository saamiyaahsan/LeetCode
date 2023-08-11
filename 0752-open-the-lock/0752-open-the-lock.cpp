class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string>st;
        
        for(auto it : deadends)
        {
            st.insert(it);
        }
        
        if(st.find(target) != st.end() || st.find("0000") != st.end())
        {
            return -1;
        }
        queue<pair<string,int>>q;
        
        q.push({"0000",0});
        st.insert("0000");
        
        while(q.empty() != true)
        {
            auto it = q.front();
            q.pop();
            string curr = it.first;
            int steps = it.second;
            
            if(curr == target)
            {
                return steps;
            }
          
            for(int i=0;i<4;i++)
            {
               string up = curr;
               string down = curr; 
                
               char u = up[i];
               char d = down[i];
                
                if(u == '9')
                {
                    up[i] = '0';
                }
                
                else
                {
                    up[i] = u + 1;
                }
                
                if(d == '0')
                {
                    down[i] = '9';
                }
                
                else
                {
                    down[i] = d - 1;
                }
                
                if(st.find(up) == st.end())
                {
                    q.push({up,steps+1});
                    st.insert(up);
                }
                
                if(st.find(down) == st.end())
                {
                    q.push({down,steps+1});
                    st.insert(down);
                }
            }
        }
        
        return -1;
    }
};