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
    Node* lowestCommonAncestor(Node* p, Node * q) {
        
        Node* x = p; 
        Node* y = q;
        
        while(x != y)
        {
            if(x == NULL)
            {
                x = q;
            }
            
            else
            {
                x = x->parent;
            }
            
            if(y == NULL)
            {
                y = p;
            }
            
            else
            {
                y = y->parent;
            }
        }
        
        return x;
    }
};