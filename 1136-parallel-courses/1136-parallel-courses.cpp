class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        
        queue<int>q;
        
        vector<vector<int>>adj(n);
        
        vector<int>indegree(n,0);
        
        for(int i=0;i<relations.size();i++)
        {
            adj[relations[i][0]-1].push_back(relations[i][1]-1);
            indegree[relations[i][1]-1]++;
        }
        
        vector<int>visited(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        if(q.empty() == true)
        {
            return -1;
        }
        
        int ans = 0;
        
        while(q.empty() != true)
        {
            int N = q.size();
            
            ans++;
            
            for(int i=0;i<N;i++)
            {
                int x = q.front();
                q.pop();
                
                visited[x] = true;
                
                for(auto it : adj[x])
                {
                     indegree[it]--;
                     if(indegree[it] == 0)
                     {
                         q.push(it);
                     }
                }
            }
        }
        
        for(int i=0;i<visited.size();i++)
        {
            if(visited[i] == 0)
            {
                return -1;
            }
        }
        
        return ans;
    }
};