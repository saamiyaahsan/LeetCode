class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

     vector<vector<int>>dist(grid.size(),vector<int>(grid[0].size(),1e9));   
        
      dist[0][0] = 0;  
      
      pq.push({0,{0,0}});  
      
      int drow[] = {-1,0,0,1};  
      int dcol[] = {0,-1,1,0};
        
      while(pq.empty() != true)  
      {
          auto x = pq.top();
          pq.pop();
          
          int diff = x.first;
          int row = x.second.first;
          int col = x.second.second;
          
          if(row == grid.size()-1 && col == grid[0].size()-1)
          {
              return diff;
          }
          
          for(int i=0;i<4;i++)
          {
              int nrow = row + drow[i];
              int ncol = col + dcol[i];
              
              if(nrow >= 0 && nrow <= grid.size()-1 && ncol >= 0 && ncol <= grid[0].size()-1)
              {
                  int newEffort = max(abs(grid[nrow][ncol]-grid[row][col]),diff);
                  
                  if(newEffort < dist[nrow][ncol])
                  {
                      dist[nrow][ncol] = newEffort;
                      pq.push({newEffort,{nrow,ncol}});
                  }
              }
          }
      }
        
     return 0; 
        
    }
};