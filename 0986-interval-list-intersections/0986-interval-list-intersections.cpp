class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        vector<int>res;
        
        vector<vector<int>>ans;
        
        int i,j;
        
        i = 0;
        j = 0;
        while(i < firstList.size() && j < secondList.size())
        {
            if(firstList[i][1] >= secondList[j][0] && firstList[i][0] <= secondList[j][1])
            {
                int p = max(firstList[i][0],secondList[j][0]);
                int q = min(firstList[i][1],secondList[j][1]);
                res.push_back(p);
                res.push_back(q);
                
                ans.push_back(res);
                res.clear();
            }
            
            
            if(firstList[i][1] > secondList[j][1])
            {
                j++;
            }
            
            else
            {
                i++;
            }
        }
        
        return ans;
    }
};