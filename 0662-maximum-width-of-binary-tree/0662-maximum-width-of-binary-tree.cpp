class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*,int>>q;
        
        if(root == NULL)
        {
            return 0;
        }
        
        q.push({root,0});
        
        int ans = INT_MIN;
        
        while(q.empty() != true)
        {
            long n = q.size();
            
            int start = q.front().second;
            int end = q.back().second;
            
            ans = max(ans,end-start+1);
            
            for(int i = 0;i < n;i++)
            {
               pair<TreeNode*,int>p = q.front();
               q.pop();
                
               TreeNode* node = p.first;
               long index = p.second;
                
               if(node->left != NULL)
               {
                   q.push({node->left,2*index + 1});
               }
                
               if(node->right != NULL)
               {
                   q.push({node->right,2*index + 2});
               }
            }
        }
        
        return ans;
    }
};