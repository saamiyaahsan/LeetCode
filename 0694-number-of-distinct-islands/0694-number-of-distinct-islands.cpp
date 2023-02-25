class Solution {
public:
    set<string> s;
    int numDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    string code = "";
                    dfs(grid, i, j, code, 'X');
                    // cout<<code<<endl;
                    s.insert(code);
                }
            }
        }
        
        return s.size();
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, string& code, char c){
        int n = grid.size();
        int m = grid[0].size();
        
        code += c;
        
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == 0)
            return;
        
        grid[i][j] = 0;
        dfs(grid, i+1, j, code, 'D');
        dfs(grid, i, j+1, code, 'R');
        dfs(grid, i-1, j, code, 'L');
        dfs(grid, i, j-1, code, 'U');
    }
};