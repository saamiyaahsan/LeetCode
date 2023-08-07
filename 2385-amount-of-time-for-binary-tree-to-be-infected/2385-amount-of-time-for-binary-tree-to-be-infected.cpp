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
    
    void Parent_child(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent)
    {
        parent[root] = NULL;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(q.empty() != true)
        {
            auto x = q.front();
            q.pop();
            
            if(x->left != NULL)
            {
                parent[x->left] = x;
                q.push(x->left);
            }
            
            if(x->right != NULL)
            {
                parent[x->right] = x;
                q.push(x->right);
            }
        }
        
    }
    int amountOfTime(TreeNode* root, int start) {
        
        unordered_map<TreeNode*,TreeNode*>parent;
        
        unordered_map<TreeNode*,bool>visited;
        
        Parent_child(root,parent);
        
        queue<TreeNode*>q;
        queue<pair<TreeNode*,int>>Q;
        
        q.push(root);
        
        while(q.empty() != true)
        {
            auto t = q.front();
            q.pop();
            
            if(t->val == start)
            {
                Q.push({t,0});
                visited[t] = true;
                break;
            }
            
            if(t->left != NULL)
            {
                q.push(t->left);
            }
            
            if(t->right != NULL)
            {
                q.push(t->right);
            }
        }
        
        int ans = 0;
        
        while(Q.empty() != true)
        {   

            auto t = Q.front();
            Q.pop();
            
            TreeNode* y = t.first;
            int time = t.second;
            ans = max(ans,time);
            
            if(parent[y] != NULL && visited[parent[y]] == false)
            {
                visited[parent[y]] = true;
                Q.push({parent[y],time+1});
            }
            
            if(y->left != NULL && visited[y->left] == false)
            {
                visited[y->left] = true;
                Q.push({y->left,time+1});
            }
            
            if(y->right != NULL && visited[y->right] == false)
            {
                visited[y->right] = true;
                Q.push({y->right,time+1});
            }
        }
        
        return ans;
    }
};