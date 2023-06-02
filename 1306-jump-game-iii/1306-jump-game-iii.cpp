class Solution {
public:
    
    bool func(vector<int>& arr,int ind,vector<int>& visited)
    {
        visited[ind] = 1;
        
        if(arr[ind] == 0)
        {
            return true;
        }
        
        if(ind + arr[ind] < arr.size() && visited[ind + arr[ind]] == 0)
        {
            if(func(arr,ind + arr[ind],visited) == true)
            {
                return true;
            }
        }
        
         if(ind - arr[ind] < arr.size() && visited[ind - arr[ind]] == 0)
        {
            if(func(arr,ind - arr[ind],visited) == true)
            {
                return true;
            }
        }
        
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        
        vector<int>visited(arr.size(),0);
        
        return func(arr,start,visited);
    }
};