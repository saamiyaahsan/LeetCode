class Solution {
public:
    
    void helper(vector<vector<int>>& graph,int source,vector<int>curr_path,vector<vector<int>>& path,int target)
    {
        curr_path.push_back(source);
        
        if(source == target)
        {
            path.push_back(curr_path);
            return;
        }
        
        for(auto it : graph[source])
        {
            helper(graph,it,curr_path,path,target);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
     
        vector<int>curr_path;
        vector<vector<int>>path;
        
        int n = graph.size();
        
        helper(graph,0,curr_path,path,n-1);
        
        return path;
    }
};