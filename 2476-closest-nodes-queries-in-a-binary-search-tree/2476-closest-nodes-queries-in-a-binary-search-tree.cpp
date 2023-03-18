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
    
    int findmax(vector<int>& res,int num)
    {
        int i = 0,j = res.size()-1,k = -1;
        
        while(i <= j)
        {
            int mid = (i+j)/2;
            
            if(res[mid] > num)
            {
                k = res[mid];
                j = mid-1;
            }
            
            else if(res[mid] == num)
            {
                return res[mid];
            }
            
            else
            {
                i = mid + 1;
            }
        }
        
        return k;
    }
    
    int findmin(vector<int>& res,int num)
    {
        int i = 0,j = res.size()-1,k = -1;
        
        while(i <= j)
        {
            int mid = (i+j)/2;
            
            if(res[mid] < num)
            {
                k = res[mid];
                i = mid + 1;
            }
            
            else if(res[mid] == num)
            {
                return res[mid];
            }
            
            else
            {
                j = mid-1;
            }
        }
        
        return k;
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        
         vector<int>res;
         inorder(root,res);
         
         vector<vector<int>>ans;
          
         for(int i=0;i<queries.size();i++)
         {
            vector<int>p;
            
             int x = findmin(res,queries[i]);
             int y = findmax(res,queries[i]);
             p.push_back(x);
             p.push_back(y);
             ans.push_back(p);
             p.clear();
         }
        
        return ans;
    }
};