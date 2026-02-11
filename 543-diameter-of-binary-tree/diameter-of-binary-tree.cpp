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
    int recFun(TreeNode* root, int &dia){
        if(!root) return NULL;
        int left_val = recFun(root->left, dia);
        int right_val = recFun(root->right, dia);

        dia = max(dia, left_val + right_val);

        return 1 + max(left_val, right_val);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        recFun(root, dia);
        return dia;
    }
};