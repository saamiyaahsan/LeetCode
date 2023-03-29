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
    
    void helper(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent,unordered_map<TreeNode*,int>& outdegree)
    {
        if(root == NULL)
        {
            return;
        }
        
        if(root->left != NULL)
        {
            parent[root->left] = root;
            outdegree[root]++;
        }
        
        else
        {
            outdegree[root] = outdegree[root] + 0;
        }
        if(root->right != NULL)
        {
            parent[root->right] = root;
            outdegree[root]++;
        }
        
        else
        {
            outdegree[root]  = outdegree[root] + 0;
        }
        helper(root->left,parent,outdegree);
        helper(root->right,parent,outdegree);
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        
        unordered_map<TreeNode*,TreeNode*>parent;
        
        unordered_map<TreeNode*,int>outdegree;
        
        helper(root,parent,outdegree);
        
        queue<TreeNode*>q;
        
        for(auto it : outdegree)
        {
            if(it.second == 0)
            {
                q.push(it.first);
            }
        }
        
        vector<vector<int>>ans;
        
        vector<int>res;
        
        while(q.empty() != true)
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                
                res.push_back(t->val);
                
                if(parent[t] != NULL)
                {
                    outdegree[parent[t]]--;
                    
                    if(outdegree[parent[t]] == 0)
                    {
                        q.push(parent[t]);
                    }
                }
            }
            
            ans.push_back(res);
            res.clear();
        }
        
        return ans;
    }
};