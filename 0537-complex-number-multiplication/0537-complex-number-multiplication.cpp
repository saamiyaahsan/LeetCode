class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        
        string real1,real2,img1,img2;
        
        int i = 0;
        
        while(num1[i] != '+')
        {
            real1 = real1 + num1[i];
            i++;
        }
        
        img1 = num1.substr(i+1,num1.size()-2);
        
        i = 0;
        
        while(num2[i] != '+')
        {
            real2 = real2 + num2[i];
            i++;
        }
        
        img2 = num2.substr(i+1,num2.size()-2);
        
        int r1,r2,i1,i2;
        
        r1 = stoi(real1);
        r2 = stoi(real2);
        i1 = stoi(img1);
        i2 = stoi(img2);
        
        int x,y;
        
        x = (r1*r2)-(i1*i2);
        y = (r1*i2)+(r2*i1);
        
        
        string t;
        
        t = to_string(x) + '+' + to_string(y) + 'i';
        
        return t;
    }
};