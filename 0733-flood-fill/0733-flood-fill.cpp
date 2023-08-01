class Solution {
public:
    
    void dfs(vector<vector<int>>& image,int i,int j,int colour,int newColour)
    {
        if(i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] != colour || image[i][j] == newColour)
        {
            return;
        }
        
        image[i][j] = newColour;
        
        dfs(image,i-1,j,colour,newColour);
        dfs(image,i+1,j,colour,newColour);
        dfs(image,i,j-1,colour,newColour);
        dfs(image,i,j+1,colour,newColour);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        dfs(image,sr,sc,image[sr][sc],color);
        
        return image;
    }
};