class Solution {
public:
    
    bool dfs(vector<vector<char>>& board,int i,int j,int index,string word)
    {
       if(index == word.size())
       {
           return true;
       }
        
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index] || board[i][j] == '*')
        {
            return false;
        }
        
        char x = board[i][j];
        
        board[i][j] = '#';
        
        bool left = dfs(board,i-1,j,index+1,word);
        bool right = dfs(board,i+1,j,index+1,word);
        bool top = dfs(board,i,j-1,index+1,word);
        bool bottom = dfs(board,i,j+1,index+1,word);
        
        board[i][j] = x;
        
        return left || right || top || bottom;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j] == word[0])
                {
                    if(dfs(board,i,j,0,word) == true)
                    {
                        return true;
                    }
                }
            }
        }
        
        
        return false;
    }
};