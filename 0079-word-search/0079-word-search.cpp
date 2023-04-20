class Solution {
public:
    
    bool dfs(vector<vector<char>>& board,int i,int j,int index,string word)
    {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index])
        {
            return false;
        }
        
        if(index == word.size()-1)
        {
            return true;
        }
        
        char X = board[i][j];
        
        board[i][j] = '0';
        
        bool x = dfs(board,i+1,j,index+1,word);
        bool y = dfs(board,i-1,j,index+1,word);
        bool z = dfs(board,i,j-1,index+1,word);
        bool w = dfs(board,i,j+1,index+1,word);
        
        board[i][j] = X;
        
        return x || y || z || w;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i = 0;i < board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j] == word[0])
                {
                    bool x = dfs(board,i,j,0,word);
                    
                    if(x == true)
                    {
                        return true;
                    }
                }
            }
        }
        
        return false;
        
    }
};