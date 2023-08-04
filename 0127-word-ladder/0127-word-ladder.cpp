class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       
        queue<pair<string,int>>q;
        
        set<string>st;
        
        for(auto it : wordList)
        {
            st.insert(it);
        }
        
        q.push({beginWord,1});
        
        if(st.find(beginWord) != st.end())
        {
            st.erase(beginWord);
        }
        
        while(q.empty() != true)
        {
            auto x = q.front();
            q.pop();
            string word = x.first;
            int steps = x.second;
            
            if(word == endWord)
            {
                return steps;
            }
            
            for(int i=0;i<word.size();i++)
            {
                char original = word[i];
                
                for(char ch ='a';ch<='z';ch++)
                {
                    word[i] = ch;
                    
                    if(st.find(word) != st.end())
                    {
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                
                word[i] = original;
            }
        }
        
        return 0;
    }
};