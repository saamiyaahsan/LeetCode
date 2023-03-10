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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        vector<long long>res;
        
        while(q.empty() != true)
        {
            int n = q.size();
            long long sum = 0;
            for(int i=0;i<n;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                
                sum = sum + t->val;
                
                if(t->left != NULL)
                {
                    q.push(t->left);
                }
                
                if(t->right != NULL)
                {
                    q.push(t->right);
                }
            }
            
            res.push_back(sum);
            sum = 0;
        }
        
        sort(res.begin(),res.end());
        
        if(res.size() < k)
        {
            return -1;
        }
        return res[res.size()-k];
    }
};