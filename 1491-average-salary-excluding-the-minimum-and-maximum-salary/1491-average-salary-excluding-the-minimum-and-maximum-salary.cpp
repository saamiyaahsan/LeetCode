class Solution {
public:
    double average(vector<int>& salary) {
        
        sort(salary.begin(),salary.end());
        
        double sum = 0,cnt = 0;
        
        for(int i=0;i<salary.size();i++)
        {
            sum = sum + salary[i];
            cnt++;
        }
        
        sum = sum - salary[0] - salary[salary.size()-1];
        
        sum = sum/(cnt-2);
    
       return sum;
    }
};