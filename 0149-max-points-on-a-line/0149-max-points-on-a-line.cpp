class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int ans = 0;
        
        if(points.size() <= 2)
        {
           return points.size();    
        }
        
        for(int i=0;i<points.size();i++)
        {
             int x1 = points[i][0];
             int y1 = points[i][1];
            
             for(int j=i+1;j<points.size();j++)
             {
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                int count = 2; 
                 
                for(int k = j+1;k<points.size();k++) 
                {
                    int x3 = points[k][0];
                    int y3 = points[k][1];
                    
                    if((x2-x1)*(y3-y1) == (y2-y1)*(x3-x1))
                    {
                        count++;
                    }
                }
                 
                ans = max(ans,count); 
             }
        }
        
        return ans;
    }
};