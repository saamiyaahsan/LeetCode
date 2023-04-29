class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>indegree(numCourses,0);
        
        vector<int>visited(numCourses,0);
        
        vector<vector<int>>adj(numCourses);
        
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        
        queue<int>q;
        
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
        
        if(cnt == numCourses)
        {
            return true;
        }
        
        return false;
    }
};