class Solution 
{
public:
    #define EMPTYROOM INT_MAX
    #define GATE 0
    #define WALL -1
    
    // vector<vector<int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // Right , Down, Left, Up
    

    void wallsAndGates(vector<vector<int>>& rooms) 
    {
        if (rooms.size() == 0 || rooms[0].size() == 0)
        {
            return;
        }
        
        queue<pair<int, int>> q;
        for (int r=0; r<rooms.size(); r++)
        {
            for (int c=0; c<rooms[0].size(); c++)
            {
                if (rooms[r][c] == GATE)
                {
                    q.push({r, c});
                }
            }
        }
        
        vector<int>drow = {-1,0,1,0};
        vector<int>dcol = {0,1,0,-1};
        while (!q.empty())
        {
            pair<int, int> curCell = q.front();
            q.pop();
            int curRow = curCell.first;
            int curCol = curCell.second;
            
            // look at all the neighbor cells
            for (int i=0;i<drow.size();i++)
            {
                int nextRow = curRow + drow[i];
                int nextCol = curCol + dcol[i];
                
                if (nextRow < 0  ||  nextRow >= rooms.size()  ||  nextCol < 0  ||  nextCol >= rooms[0].size()  ||  rooms[nextRow][nextCol] == WALL  ||  rooms[nextRow][nextCol] != EMPTYROOM)
                {
                    continue;
                }
                
                rooms[nextRow][nextCol] = rooms[curRow][curCol] + 1;
                q.push({nextRow, nextCol});
            }
        }
    }
};