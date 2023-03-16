class Solution {
 public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        queue<int>q;
        
//         vector<int>adj[rooms.size()];
        
//         for(int i=0;i<rooms.size();i++)
//         {
//             adj[i].push_back(rooms[i]);
//         }
        
        vector<int>visited(rooms.size(),0);
        
        q.push(0);
        
        visited[0] = 1;
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                int t = q.front();
                q.pop();
                for(auto it : rooms[t])
                {  
                    if(visited[it] != 1)
                    {
                        q.push(it);
                        visited[it] = 1;
                    }
                }  
            }
        }
        
        for(int i=0;i<rooms.size();i++)
        {
            if(visited[i] == 0)
            {
                return false;
            }
        }
        
        return true;
    }
};