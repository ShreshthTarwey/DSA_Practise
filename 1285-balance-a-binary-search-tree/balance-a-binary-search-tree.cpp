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
    void recFun(TreeNode* root, vector<int>&ans){
        if(!root) return;
        recFun(root->left, ans);
        ans.push_back(root->val);
        recFun(root->right, ans);
    }
    TreeNode* buildTree(vector<int>& arr, int start, int end){
        if(start>end){
            return NULL;
        }
        int mid = (start+end)/2;
        if(mid>=arr.size() || mid<0) return NULL;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = buildTree(arr,start, mid-1);
        root->right = buildTree(arr, mid+1, end);
        return root;
    }
    TreeNode* bruteForce(TreeNode* root){
        vector<int>arr;
        recFun(root, arr);
        int start = 0;
        int end = arr.size();
        // TreeNode* dummy = new TreeNode(0);
        // TreeNode* temp = dummy;
        return buildTree(arr, start, end);

    }
    TreeNode* balanceBST(TreeNode* root) {
        return bruteForce(root);
    }
};