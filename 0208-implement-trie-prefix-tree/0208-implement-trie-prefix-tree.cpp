class TrieNode
{   
    private:  
    TrieNode* links[26];
    bool flag = false;
    
    public:
    bool containsKey(char ch)
    {
        return links[ch-'a'] != NULL;
    }
    
    void put(char ch,TrieNode* node)
    {
        links[ch-'a'] = node;
    }
    
    TrieNode* get(char ch)
    {
        return links[ch-'a'];
    }
    
    bool setEnd()
    {
        flag = true;
        return flag;
    }
    
    bool isEnd()
    {
        return flag;
    }
};


class Trie {

private:
    TrieNode* root;
    
public:
    Trie() {
        
        root = new TrieNode();
        
    }
    
    void insert(string word) {
        
        TrieNode* node = root;
        
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i]) == NULL)
            {
                node->put(word[i],new TrieNode());
            }
            
            // moves to the reference trie
            node = node->get(word[i]);
        }
        
        node->setEnd();
    }
    
    bool search(string word) {
        
        TrieNode* node = root;
        
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i]) == NULL)
            {
                return false;
            }
            
            node = node->get(word[i]);
        }
        
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        
        TrieNode* node = root;
        
        for(int i=0;i<prefix.size();i++)
        {
            if(node->containsKey(prefix[i]) == NULL)
            {
                return false;
            }
            
            node = node->get(prefix[i]);
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */