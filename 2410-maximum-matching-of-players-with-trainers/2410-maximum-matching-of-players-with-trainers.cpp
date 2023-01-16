class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        
//         int k;
        
//         k = min(players.size(),trainers.size());
        
        int i,j,cnt = 0;
        
        i = 0;
        j = 0;
        while(i < players.size() && j < trainers.size())
        {
            if(players[i] <= trainers[j])
            {
                cnt++;
                i++;
                j++;
            }
            
            else
            {
                j++;
            }
        }
        
        return cnt;
    }
};