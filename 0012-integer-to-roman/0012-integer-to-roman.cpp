class Solution {
public:
    string intToRoman(int num) {
        
        vector<int> numbers = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string> roman = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        
        string res;
        
        for(int i=numbers.size()-1;i>=0;i--)
        {
            while(num >= numbers[i])
            {
                res = res + roman[i];
                num = num-numbers[i];
            }
        }
        
        return res;
    }
};