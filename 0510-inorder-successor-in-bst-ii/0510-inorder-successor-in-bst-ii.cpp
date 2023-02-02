/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    
    void inorder(Node* root,vector<int>& res)
    {
        if(root == NULL)
        {
            return;
        }
        
        if(root->left != NULL)
        {
            inorder(root->left,res);
        }
        
        res.push_back(root->val);
        
        if(root->right != NULL)
        {
            inorder(root->right,res);
        }
    }
    Node* inorderSuccessor(Node* node) {
        
        Node* root;
        
        root = node;
        
        vector<int>res;
        
        while(root->parent != NULL)
        {
            root = root->parent;
        }
        
        inorder(root,res);
        
        int c;
        
        for(int i=0;i<res.size();i++)
        {
            if(res[i] == node->val)
            {
                c = i;
                break;
            }
        }
        
        if(c == res.size()-1)
        {
            return NULL;
        }
        
        Node* ans = new Node(res[c+1]);
        
        return ans;
    }
};