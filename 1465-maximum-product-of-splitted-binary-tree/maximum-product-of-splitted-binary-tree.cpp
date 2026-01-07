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
    long SUM = 0;
    long maxP = 0;
    int MOD = 1e9+7;
    int totalSum(TreeNode* root){
        if(!root) return 0;
        return root->val + totalSum(root->left) + totalSum(root->right);
    }

    int find(TreeNode* root){
        if(!root) return 0;
        int subTreeSum = root->val + find(root->left) + find(root->right);
        maxP = max(maxP,(SUM-subTreeSum)* subTreeSum);
        // return 0;
        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {
       SUM =  totalSum(root);
       find(root);
       return maxP % MOD;
    }
};