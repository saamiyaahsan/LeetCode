class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        
        int cnt = 0,res = 0;
        
        for(int i=0;i<moves.size();i++)
        {
            if(moves[i] == 'L')
            {
                cnt--;
                res--;
            }
            
            else if(moves[i] == '_')
            {
                cnt++;
                res--;
            }
            
            else
            {
                cnt++;
                res++;
            }
        }
        
        return max(abs(cnt),abs(res));
    }
};