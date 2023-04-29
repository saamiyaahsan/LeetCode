class Solution {
public:
    
    void dfs(vector<vector<int>>& adj,int node,vector<bool>& visited)
    {
        visited[node] = true;
        
        for(auto it : adj[node])
        {   
            if(visited[it] != true)
            {
               dfs(adj,it,visited);    
            }
        }
    }
    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<vector<int>>adj(numCourses);
        
        vector<bool>res;
        
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        for(int i=0;i<queries.size();i++)
        {
            int x = queries[i][0];
            int y = queries[i][1];
            vector<bool>visited(numCourses,false);    
            dfs(adj,x,visited);
            res.push_back(visited[y]);
        }
        
        return res;
    }
};