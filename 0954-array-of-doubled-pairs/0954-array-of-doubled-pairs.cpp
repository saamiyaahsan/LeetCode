class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        
        unordered_map<int,int>mp;
        
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        
        for(int i=0;i<arr.size();i++)
        {
            if(mp[arr[i]] == 0)
            {
               continue;    
            }
            
            if(mp[arr[i]] > 0)
            {   
                if(mp[2*arr[i]] > 0)
                {
                     mp[arr[i]]--;
                    mp[2*arr[i]]--;
                }
                
            }
        }
        
        for(auto it : mp)
        {
            if(it.second != 0)
            {
                return false;
            }
        }
        
        return true;
    }
};