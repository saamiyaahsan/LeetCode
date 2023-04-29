class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>res;
        
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);
        
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        
        queue<int>q;
        
        int cnt = 0;
        
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        while(q.empty() != true)
        {
            int x = q.front();
            q.pop();
            
            cnt++;
            res.push_back(x);
            
            for(auto it : adj[x])
            {
                indegree[it]--;
                
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        
        if(cnt != numCourses)
        {
            res.clear();
            return res;
        }
        
        return res;
    }
};