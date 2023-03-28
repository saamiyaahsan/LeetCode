class Solution {
public:
    
    void dfs(int node,vector<int>& visited,vector<vector<int>>& adj)
    {
        visited[node] = 1;
        
        for(auto it : adj[node])
        {
            if(visited[it] != 1)
            {
               dfs(it,visited,adj);    
            }
            
        }
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        vector<vector<int>>edges;
        vector<int>visited(n,0);
        vector<int>res;
        
             vector<int>indegree(n,0);
        
        for(int i=0;i<leftChild.size();i++)
        {
            if(leftChild[i] != -1)
            {
                res.push_back(i);
                  res.push_back(leftChild[i]);
                edges.push_back(res);
                res.clear();
                indegree[leftChild[i]]++;
            }
            
            if(rightChild[i] != -1)
            {
                 res.push_back(i);
                  res.push_back(rightChild[i]);
                edges.push_back(res);
                indegree[rightChild[i]]++;
                res.clear();
            }
        }
        
        vector<vector<int>>adj(n);
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        int cnt = 0,p=0;
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i] > 1)
            {
                return false;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i] == 0)
            {
                p = i;
                cnt++;
            }
        }
        
        if(cnt == 0 || cnt > 1)
        {
            return false;
        }
        
        dfs(p,visited,adj);
        
        for(int i=0;i<n;i++)
        {
            if(visited[i] == 0)
            {
                return false;
            }
        }
        
        return true;
    }
};