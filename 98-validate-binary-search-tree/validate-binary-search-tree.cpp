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
    void recFun(TreeNode* root, vector<int>& nums){
        if(!root) return;

        recFun(root->left, nums);
        nums.push_back(root->val);
        recFun(root->right, nums);
    }
    bool inOrderMethod(TreeNode* root){
        vector<int>nums;
        recFun(root, nums);
        // vector<int>nums2 = nums;
        // sort(nums2.begin(), nums2.end());
        // return nums2 == nums;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>=nums[i+1]){
                return false;
            }
        }
        return true;
    }
    bool isValidBST(TreeNode* root, long long minm = LLONG_MIN, long long maxm = LLONG_MAX) {
        // return inOrderMethod(root);
        if(!root) return true;

        if(root->val>=maxm || root->val<=minm) return false;

        return isValidBST(root->left, minm, root->val) && isValidBST(root->right, root->val, maxm);
    }
};