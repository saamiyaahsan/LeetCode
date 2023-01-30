class Solution {
public:
    int tribonacci(int n) {
        
      vector<int>Tribonacci(38);
      
        Tribonacci[0] = 0;
        Tribonacci[1] = 1;
        Tribonacci[2] = 1;
        
        for(int i=3;i<=n;i++)
        {
            Tribonacci[i] = Tribonacci[i-1] + Tribonacci[i-2] + Tribonacci[i-3];
        }
        
        return Tribonacci[n];
    }
};