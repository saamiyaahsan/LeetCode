class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
         unordered_map<int,int>mp; 
         
         vector<int>res;
         
         sort(changed.begin(),changed.end());
         
         for(int i=0;i<changed.size();i++)
         {
             mp[changed[i]]++;
         }
        
         for(int i=0;i<changed.size();i++) 
         {
             if(mp[changed[i]] > 0)
             {
                 mp[changed[i]]--;
                 
                 if(mp[2*changed[i]] > 0)
                 {
                     res.push_back(changed[i]); 
                     mp[2*changed[i]]--;
                 }
                 
                 else
                 {
                     res.clear();
                     return res;
                 }
             }
         }
        
        return res;
    }
};