class Solution {
public:
    
   
     
     void bfs(vector<vector<int>>& adj,int node,vector<vector<int>>& ans)
     {
         queue<int>q;
         
         vector<bool>visited(adj.size(),false);
         
         q.push(node);
         visited[node] = 1;
         
         while(q.empty() != true)
         {
                 int x = q.front();
                 q.pop();
                 for(auto &it : adj[x])
                {
                     if(visited[it] == false)
                    {
                          visited[it] = true; 
                       ans[it].push_back(node);
                       q.push(it);
                     }
                } 
            
         }
        
     }
     vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
      
     vector<vector<int>>adj(n);   
     
     for(int i=0;i<edges.size();i++)   
     {
         adj[edges[i][0]].push_back(edges[i][1]);
     }   
     
          vector<vector<int>> ans(n);
         
         for(int i=0;i<n;i++)
         {
             bfs(adj,i,ans);         
         }
         
         return ans;
      
    }
};