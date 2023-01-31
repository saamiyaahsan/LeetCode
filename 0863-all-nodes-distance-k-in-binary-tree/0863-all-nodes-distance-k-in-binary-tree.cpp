/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void Markparents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parents)
    {
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(q.empty() != true)
        {
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left != NULL)
            {
                parents[node->left] = node;
                q.push(node->left);
            }
            
            if(node->right != NULL)
            {
                parents[node->right] = node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*,TreeNode*>parents;
        Markparents(root,parents);
        
        unordered_map<TreeNode*,bool>visited;
        
        queue<TreeNode*>q;
        
        q.push(target);
        
        visited[target] = true;
        
        int currLevel = 0;
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            if(currLevel++ == k)
            {
               break;    
            }
            
            for(int i=0;i<n;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr->left != NULL && visited[curr->left] == false)
                {
                    visited[curr->left] = true;
                    q.push(curr->left);
                }
                
                if(curr->right != NULL && visited[curr->right] == false)
                {
                    visited[curr->right] = true;
                    q.push(curr->right);
                }
                
                if(parents[curr] != NULL && visited[parents[curr]] == false)
                {
                    visited[parents[curr]] = true;
                    q.push(parents[curr]);
                }
            }
        }
        
        vector<int>res;
        
        while(q.empty() != true)
        {
            TreeNode* p = q.front();
            
            res.push_back(p->val);
            q.pop();
        }
        
        return res;
    }
};