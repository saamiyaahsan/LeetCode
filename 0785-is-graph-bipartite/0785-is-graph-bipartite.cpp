class Solution {
public:
    
    bool helper(vector<vector<int>>& graph,int node,vector<int>& color)
    {
        queue<int>q;
        
        color[node] = 0;
        
        q.push(node);
        
        while(q.empty() != true)
        {
            int x = q.front();
            q.pop();
            
            for(auto it : graph[x])
            {
                if(color[it] == -1)
                {
                    if(color[x] == 1)
                    {
                        color[it] = 0;
                    }
                    
                    else
                    {
                        color[it] = 1;
                    }
                    
                     q.push(it);
                }
                
                if(color[it] == color[x])
                {
                    return false;
                }
                
               
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int>color(graph.size(),-1);
        
        for(int i=0;i<graph.size();i++)
        {
            if(color[i] == -1)
            {   
                if(helper(graph,i,color) == false)
                {
                    return false;     
                }
               
            }
        }
        
        return true;
    }
};