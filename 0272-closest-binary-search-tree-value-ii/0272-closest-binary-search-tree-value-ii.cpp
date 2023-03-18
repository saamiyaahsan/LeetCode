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
    
    void inorder(TreeNode* root,vector<int>& res)
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
    
    vector<int> closestKValues(TreeNode* root, double target, int k) {
       
       vector<int>res; 
        
       inorder(root,res);
        
       priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>>pq;    
       
       for(int i=0;i<res.size();i++) 
       {
           double x = abs(res[i]-target);
           pq.push({x,res[i]});
       }
        
       vector<int>ans;
        
       while(k != 0 && !pq.empty()) 
       {
           auto x = pq.top();
           pq.pop();
           ans.push_back(x.second);
           k--;
       } 
       
       return ans;
        
    }
};