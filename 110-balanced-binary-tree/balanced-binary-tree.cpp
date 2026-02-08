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
    int recFun(TreeNode* root, bool &flag){
        if(!root){
            return 0;
        }
        int left = recFun(root->left, flag);
        int right = recFun(root->right, flag);
        if(abs(left-right)>=2) flag = false;
        return 1 + max(left, right);

    }
    bool isBalanced(TreeNode* root) {
        bool flag = true;
        recFun(root, flag);
        return flag;
    }
};