class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        
           int ans = 0;
       
        if(points.size() < 3)
        {
            return 0;
        }
        
      for(int i=0;i<points.size();i++)
         {
                map<int,int>mp;
        
            
             for(int j=0;j<points.size();j++)
             {
                 if(i == j)
                 {
                     continue;
                 }
                 
                 else
                 {
                     int distance = pow((points[i][0] - points[j][0]),2);
                     distance = distance + pow((points[i][1]-points[j][1]),2);
                     mp[distance]++;
                 }
             }
          
              for(auto it : mp)
        {
            if(it.second <= 1)
            {
                continue;
            }
            
            else
            {
                ans = ans + it.second*(it.second-1);
            }
        }
         }
        
           
        return ans;
    }
};