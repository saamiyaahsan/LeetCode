/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    map<char,int>mp1;
    map<char,int>mp2;
    
    void helper(Node* root,map<char,int>& mp)
    {
        if(root == NULL)
        {
            return;
        }
        
        mp[root->val]++;
        
        if(root->left != NULL)
        {
            helper(root->left,mp);
        }
        
         if(root->right != NULL)
        {
            helper(root->right,mp);
        }
        
    }
    bool checkEquivalence(Node* root1, Node* root2) {
        
        helper(root1,mp1);
        helper(root2,mp2);
        
        for(auto it : mp1)
        {
            if(mp2[it.first] != it.second)
            {
                return false;
            }
        }
        
          for(auto it : mp2)
        {
            if(mp1[it.first] != it.second )
            {
                return false;
            }
        }
        
        return true;
    }
};