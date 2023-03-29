class Solution {
public:
    
    void dfs(vector<vector<int>>& land,int i,int j,vector<int>& res)
    {
        if(i < 0 || i >= land.size() || j < 0 || j >= land[0].size() || land[i][j] == 0)
        {
            return;
        }
        
        land[i][j] = 0;
        
        res[0] = max(res[0],i);
        res[1] = max(res[1],j);
           
        dfs(land,i-1,j,res);
        dfs(land,i+1,j,res);
        dfs(land,i,j-1,res);
        dfs(land,i,j+1,res);
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        vector<int>res(2);
        
        vector<vector<int>>ans;
        
        vector<int>V;
        
        for(int i=0;i<land.size();i++)
        {
            for(int j=0;j<land[0].size();j++)
            {
                if(land[i][j] == 1)
                {
                    V.push_back(i);
                    V.push_back(j);
                    
                    res[0] = i;
                    res[1] = j;
                    dfs(land,i,j,res);
                    V.push_back(res[0]);
                    V.push_back(res[1]);
                    ans.push_back(V);
                    V.clear();
                }
            }
        }
        
        return ans;
    }
};