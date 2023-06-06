class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        vector<int>ahead(2,0);
        vector<int>curr(2,0);
        
        ahead[0] = 0;
        ahead[1] = 0;
        
        int n = prices.size();
        
        // j corresponds to buy;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                if(j == 1)
                {
                    curr[1] = max(-prices[i] + ahead[0],ahead[1]);
                }
                
                else
                {
                    curr[0] = max(prices[i] + ahead[1],ahead[0]);
                }
                
                ahead = curr;
            }
        }
        
        return ahead[1];
    }
};