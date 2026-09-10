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
    int ans = 0;
    int solve(TreeNode* root, int &sum){
        if(!root) return 0;
        int leftPart = 1 + solve(root->left, sum);
        int tempSum = sum;
        sum = 0;
        int rightPart = solve(root->right, sum);
        sum += root->val;
        sum += tempSum;
        if((sum)/(leftPart + rightPart) == root->val){
            ans++;
        }
        return leftPart + rightPart;
    }
    int averageOfSubtree(TreeNode* root) {
        int sum = 0;
        solve(root, sum);
        return ans;
    }
};