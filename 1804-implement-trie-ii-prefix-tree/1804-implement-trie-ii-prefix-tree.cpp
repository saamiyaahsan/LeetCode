struct Node
{
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;
    bool containsKey(char ch)
    {
        if(links[ch-'a'] != NULL)
        {
            return true;
        }
        
        return false;
    }
    
    void increaseEnd()
    {
        cntEndWith++;
    }
    
    
    void increasePrefix()
    {
        cntPrefix++;
    }
    
    void DeleteEnd()
    {
        cntEndWith--;
    }
    
    void reducePrefix()
    {
        cntPrefix--;
    }
    void put(char ch,Node* node)
    {
        links[ch-'a'] = node;
    }
    
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    
    int getEnd()
    {
        return cntEndWith;
    }
    
    int getPrefix()
    {
        return cntPrefix;
    }
};


class Trie {
    
private: Node* root;
    
public:
    Trie() {
        
        root = new Node();
        
    }
    
    void insert(string word) {
        
        Node* node = root;
        
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i]) == false)
            {
                node->put(word[i],new Node());
            }
            
            node = node->get(word[i]);
            node->increasePrefix();
        }
        
       node->increaseEnd();
        
    }
    
    int countWordsEqualTo(string word) {
        
        Node* node = root;
        
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i]) == false)
            {
                return 0;
            }
            
            node = node->get(word[i]);
        }
        
        return node->getEnd();
    }
    
    int countWordsStartingWith(string prefix) {
       Node* node = root;
        
       for(int i=0;i<prefix.size();i++) 
       {
           if(node->containsKey(prefix[i]) == false)
           {
               return 0;
           }
           
           node = node->get(prefix[i]);
       }
        
        return node->getPrefix();
    }
    
    void erase(string word) {
        Node* node = root;
        
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                node->reducePrefix();
            }
            
            else
            {
                return;
            }
        }
        
        node->DeleteEnd();
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */