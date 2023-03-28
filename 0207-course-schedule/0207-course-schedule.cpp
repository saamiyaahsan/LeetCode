class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        queue<int>q;
        
        int n = numCourses;
        
        vector<vector<int>>adj(n);
        
            vector<int>indegree(n,0);
            
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        int cnt = 0;
        
        while(q.empty() != true)
        {
                 int x = q.front();
                 q.pop();
                 cnt++;
                for(auto it : adj[x])
                {
                   indegree[it]--; 
                    
                   if(indegree[it] == 0)
                   {
                     q.push(it);
                   }
                
                }
           
        }
        
        if(cnt == n)
        {
            return true;
        }
        
        return false;
    }
};