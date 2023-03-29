class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        vector<int>res;
        
        queue<pair<int,int>>q;
        
        q.push({0,0});
        
        while(q.empty() != true)
        {
            auto x = q.front();
            q.pop();
            int row = x.first;
            int col = x.second;
            
            res.push_back(nums[row][col]);
            
            if(x.second == 0 && x.first + 1 <= nums.size()-1)
            {
                q.push({x.first+1,x.second});
            }
            
            if(x.second + 1 < nums[x.first].size())
            {
                q.push({x.first,x.second+1});
            }
        }
        
        return res;
    }
};