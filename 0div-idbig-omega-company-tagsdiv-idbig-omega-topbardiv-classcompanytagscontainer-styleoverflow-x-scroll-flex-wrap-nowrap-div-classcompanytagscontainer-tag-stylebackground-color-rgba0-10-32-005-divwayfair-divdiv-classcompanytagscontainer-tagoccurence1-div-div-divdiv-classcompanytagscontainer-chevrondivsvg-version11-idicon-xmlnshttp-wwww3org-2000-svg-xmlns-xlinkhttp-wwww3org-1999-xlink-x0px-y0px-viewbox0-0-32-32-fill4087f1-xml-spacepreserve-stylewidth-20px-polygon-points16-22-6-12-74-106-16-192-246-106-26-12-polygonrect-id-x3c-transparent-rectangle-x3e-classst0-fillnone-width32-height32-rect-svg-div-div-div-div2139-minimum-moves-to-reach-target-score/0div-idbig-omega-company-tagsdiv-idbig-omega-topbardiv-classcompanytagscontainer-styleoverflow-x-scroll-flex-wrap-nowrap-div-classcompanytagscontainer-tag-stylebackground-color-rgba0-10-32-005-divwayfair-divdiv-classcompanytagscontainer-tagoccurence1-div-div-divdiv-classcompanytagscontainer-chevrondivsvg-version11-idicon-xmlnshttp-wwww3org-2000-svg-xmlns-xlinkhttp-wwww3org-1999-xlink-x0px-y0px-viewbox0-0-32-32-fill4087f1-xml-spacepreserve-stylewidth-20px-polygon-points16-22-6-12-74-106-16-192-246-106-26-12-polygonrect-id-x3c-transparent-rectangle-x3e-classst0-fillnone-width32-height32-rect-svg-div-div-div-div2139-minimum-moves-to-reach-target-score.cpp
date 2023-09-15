class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        
        long long cnt = 0;
        
        while(target != 1)
        {
            if(maxDoubles > 0 && target % 2 == 0)
            {
                target = target/2;
                maxDoubles--;
                cnt++;
            }
            
            else if(maxDoubles == 0)
            {
                cnt = cnt + (target-1);
                break;
            }
            
            else
            {
                target = target - 1;
                cnt++;
            }
        }
        
        return cnt;
    }
};