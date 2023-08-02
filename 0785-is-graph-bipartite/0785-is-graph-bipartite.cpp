class Solution {
public:
    
    bool helper(vector<vector<int>>& graph,int node,vector<int>& color)
    { 
        for(auto it : graph[node])
        {
            if(color[it] == -1)
            {
                color[it] = 1 - color[node];
                
                if(helper(graph,it,color) == false)
                {
                    return false;
                }
            }
            
            else if(color[it] == color[node])
            {
                return false;
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
                color[i] = 0;
                if(helper(graph,i,color) == false)
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};