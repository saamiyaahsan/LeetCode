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
    
    int min_helper(vector<int>& res,int num)
    {
        int i = 0,j = res.size()-1,ans = -1;
        
        while(i <= j)
        {
            int mid = (i + j)/2;
            
            if(res[mid] == num)
            {
                return num;
            }
            
            else if(res[mid] < num)
            {
                ans = res[mid];
                i = mid + 1;
            }
            
            else
            {
                j = mid-1;
            }
        }
        
        return ans;
    }
    
    int max_helper(vector<int>& res,int num)
    {
        int i = 0,j = res.size()-1,ans = -1;
        
        while(i <= j)
        {
            int mid = (i+j)/2;
            
            if(res[mid] == num)
            {
                return num;
            }
            
            else if(res[mid] > num)
            {
                ans = res[mid];
                j = mid - 1;
            }
            
            else
            {
                i = mid + 1;
            }
        }
        
        return ans;
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        
        vector<vector<int>>ans;
        vector<int>arr;
        vector<int>res;
        
        inorder(root,res);
        
        for(int i=0;i<queries.size();i++)
        {
            int mx = min_helper(res,queries[i]);
            int mn = max_helper(res,queries[i]);
            arr.push_back(mx);
            arr.push_back(mn);
            ans.push_back(arr);
            arr.clear();
        }
        
        return ans;
    }
};