class Solution {
public:
    bool winnerOfGame(string colors) {
        
        int cntofA = 0,cntofB = 0;
        
        for(int i=1;i<colors.size();i++)
        {
            if(colors[i] == colors[i-1] && colors[i] == colors[i+1])
            {
                if(colors[i] == 'A')
                {
                    cntofA++;
                }
                
                else
                {
                    cntofB++;
                }
            }
        }
        
        return (cntofA > cntofB);
    }
};