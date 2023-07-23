/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    void helper(ListNode* head,vector<int>& res)
    {
        ListNode* p = head;
        
        while(p != NULL)
        {
            res.push_back(p->val);
            p = p->next;
        }
    }
    
    TreeNode* BuildTree(vector<int>res,int low,int high)
    {
        if(low > high)
        {
            return NULL;
        }
        
        int mid = (low + high)/2;
        
        TreeNode* root = new TreeNode(res[mid]);
        
        root->left = BuildTree(res,low,mid-1);
        root->right = BuildTree(res,mid+1,high);
        
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        
        vector<int>res;
        
        helper(head,res);
        
        return BuildTree(res,0,res.size()-1);
    }
};