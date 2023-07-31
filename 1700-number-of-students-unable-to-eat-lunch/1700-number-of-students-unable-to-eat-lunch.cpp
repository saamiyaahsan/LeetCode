class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        stack<int>st;
        queue<int>q;
        
        int ans = 0,cnt = 0;
        
        for(int i=sandwiches.size()-1;i>=0;i--)
        {
            st.push(sandwiches[i]);
        }
        
        for(int i=0;i<students.size();i++)
        {
            q.push(students[i]);
        }
        
        while(st.empty() != true)
        {
            if(q.front() == st.top())
            {
                q.pop();
                st.pop();
                cnt = 0;
            }
            
            else
            {
                q.push(q.front());
                q.pop();
                cnt++;
            }
            
            if(cnt == students.size())
            {
                break;
            }
        }
        
        return q.size();
    }
};