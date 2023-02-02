/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void Parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent)
    {
        if(root == NULL)
        {
            return;
        }
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
              TreeNode* curr = q.front();
              q.pop();
            
               if(curr->left != NULL)
              {
                parent[curr->left] = curr;
                q.push(curr->left);
              }
            
               if(curr->right != NULL)
              {
                parent[curr->right] = curr;
                q.push(curr->right);
              }     
            }
           
        }
    }
    int sumEvenGrandparent(TreeNode* root) {
        
        unordered_map<TreeNode*,TreeNode*>parent;
        
        Parent(root,parent);
        
        queue<TreeNode*>q;
        
        int sum = 0;
        
        q.push(root);
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                
                if(parent[curr] != NULL && parent[parent[curr]] != NULL && parent[parent[curr]]->val % 2 == 0)
                {
                    sum = sum + curr->val;
                }
                
                if(curr->left != NULL)
                {
                    q.push(curr->left);
                }
                
                if(curr->right != NULL)
                {
                    q.push(curr->right);
                }
            }
        }
        
        return sum;
    }
};