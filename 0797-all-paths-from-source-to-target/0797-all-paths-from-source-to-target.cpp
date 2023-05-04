class Solution {
public:
    
    void helper(vector<vector<int>>& graph,int source,int target,vector<vector<int>>& ans,vector<int>res)
    {
        //visited[source] = 1;
        
        res.push_back(source);
        
        if(source == target)
        {
            ans.push_back(res);
            return;
        }
        
        for(auto it : graph[source])
        {
             helper(graph,it,target,ans,res);
        }
        
        //visited[source] = 0;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>>ans;
        vector<int>visited(graph.size(),0);
        vector<int>res;
        
        helper(graph,0,graph.size()-1,ans,res);
        
        return ans;
    }
};