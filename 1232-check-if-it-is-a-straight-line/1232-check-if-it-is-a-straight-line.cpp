class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        
        sort(coordinates.begin(),coordinates.end());
        
        
        if(coordinates.size() == 2)
        {
            return true;
        }
        
        double p;
        
        if(coordinates[1][0]-coordinates[0][0] == 0)
        {
            p = INT_MAX;
        }
        
        else
        {
            p = (coordinates[1][1]-coordinates[0][1])/(coordinates[1][0]-coordinates[0][0]); 
        }
      
        double x;
        
        for(int i=2;i<coordinates.size();i++)
        {   
              if(coordinates[i][0]-coordinates[i-1][0] == 0)
              {
                  x = INT_MAX;
              }
          
            else
            {
               x = (coordinates[i][1]-coordinates[i-1][1])/(coordinates[i][0]-coordinates[i-1][0]); 
            }
            
            
            if(x == p)
            {
                p = x;
            }
            
            else
            {
                return false;
            }
        }
        
        return true;
    }
};