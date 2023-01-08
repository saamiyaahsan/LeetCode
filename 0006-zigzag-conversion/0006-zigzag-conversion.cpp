class Solution {
public:
    string convert(string s, int numRows) {
        
        vector<string>arr(numRows,"");
        
        if(numRows == 1)
        {
           return s;    
        }
        
        bool t = false;
        
        int curr_row = 0;
        
        for(int i=0;i<s.size();i++)
        {
            arr[curr_row].push_back(s[i]);
            
            if(curr_row == 0 || curr_row == numRows-1)
            {
                t = !t;
            }
            
            if(t == true)
            {
               curr_row++;    
            }
            
            if(t == false)
            {
                curr_row--;
            }
        }
        
        string p = "";
        
        for(int i=0;i<arr.size();i++)
        {
            p = p + arr[i];
        }
        
        return p;
    }
};