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
    bool recFun(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans){
        if(root == NULL){
            return false;
        }
        // if(ans != NULL) return true;
        bool self = (root == p || root == q);
        bool left = recFun(root->left, p, q, ans);
        bool right = recFun(root->right, p, q, ans);

        if((self && left) || (self && right) || (left && right)){
            ans = root;
        }
        return self || left || right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        recFun(root, p, q, ans);
        return ans;
    }
};