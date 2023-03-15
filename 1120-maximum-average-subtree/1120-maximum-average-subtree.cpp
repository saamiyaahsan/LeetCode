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
    
     double ans = 0;
    
    double sum(TreeNode* root, int& cnt)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        cnt++;
        double left = sum(root->left,cnt);
        double right = sum(root->right,cnt);
        return (root->val + left + right);
    }
    void solve(TreeNode* root){
        if(root==NULL) return;
        int cnt = 0;
        double avg = (sum(root,cnt))/cnt;
        
        if(ans < avg)
        {
           ans = avg; 
        }
        // ans = max(ans,avg);
        solve(root->left);
        solve(root->right);
    }
    
    double maximumAverageSubtree(TreeNode* root) {
        
        solve(root);
        
        return ans;
    }
};