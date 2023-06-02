class Solution {
public:
    
    bool func(vector<int>& arr,int ind,vector<int>& visited)
    {
        visited[ind] = 1;
        
        if(arr[ind] == 0)
        {
            return true;
        }
        
        bool p = false;
        bool q = false;
        
        if(ind + arr[ind] < arr.size() && visited[ind + arr[ind]] == 0)
        {
            p = func(arr,ind + arr[ind],visited);
        }
        
         if(ind - arr[ind] < arr.size() && visited[ind - arr[ind]] == 0)
        {
            q = func(arr,ind - arr[ind],visited);
        }
        
        return p || q;
    }
    bool canReach(vector<int>& arr, int start) {
        
        vector<int>visited(arr.size(),0);
        
        return func(arr,start,visited);
    }
};