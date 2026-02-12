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
    bool isValidBST(TreeNode* root) {
        // if(!root) return true;
        // if(root->left && root->left->val>=root->val){
        //     return false;
        // }
        // if(root->right && root->right->val<=root->val){
        //     return false;
        // }
        // bool left = isValidBST(root->left);
        // bool right = isValidBST(root->right);

        // return (left && right);
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
};