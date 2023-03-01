class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        
        priority_queue<pair<int,int>>pq;
        
        if(barcodes.size() <= 1)
        {
            return barcodes;
        }
        vector<int>res;
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<barcodes.size();i++)
        {
            mp[barcodes[i]]++;
        }
        
        for(auto it : mp)
        {
            pq.push({it.second,it.first});
        }
        
        while(pq.top().first > 0)
        {
            pair<int,int>p1 = pq.top();
            pq.pop();
            
           
            // if(p1.first > 0)
            // {
                   res.push_back(p1.second);
                   p1.first--;     
           
         
           pair<int,int>p2 = pq.top();
            pq.pop();
            
             if(p2.first > 0)
            {
                   res.push_back(p2.second);
                   p2.first--;     
            }
         
              pq.push(p1);
              pq.push(p2);
            
        }
        
        return res;
    }
};