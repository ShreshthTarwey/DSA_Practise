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
    int maxDepth(TreeNode* root){
        if(!root) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1 + max(left, right);
    }
    // void fillMap(TreeNode* root, unordered_map<TreeNode*, bool>&mp, int depth, int currDep){
    //     if(!root) return;
    //     if(currDep==depth){
    //         mp[root] = false;
    //         return;
    //     }
    //     fillMap(root->left, mp, depth, currDep+1);
    //     fillMap(root->right, mp, depth, currDep+1);
    // }
    // bool checkTrue(unordered_map<TreeNode*, bool>& mp){
    //     for(auto it: mp){
    //         if(it.second==false){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // TreeNode* recFun(TreeNode* root, unordered_map<TreeNode*, bool>& mp, int depth, int currDepth){
    //     if(!root) return NULL;
    //     if(currDepth == depth){
    //         mp[root] = true;
    //     }
    //     if(checkTrue(mp)){
    //         return root;
    //     }
    //     TreeNode* left = recFun(root->left, mp, depth, currDepth+1);
    //     TreeNode* right = recFun(root->right, mp, depth, currDepth+1);
    //     if(left) return left;
    //     return right;
    // }
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        return 1 + max(left, right);
    }
    TreeNode* recFun(TreeNode* root){
        if(!root) return NULL;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if(leftHeight==rightHeight){
            return root;
        }
        else if(leftHeight>rightHeight){
            return recFun(root->left);
        }
        else{
            return recFun(root->right);
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        // int depth = maxDepth(root);
        // cout<<depth;
        // return root;
        // unordered_map<TreeNode*, bool>mp;
        // fillMap(root, mp, depth, 1);
        // return recFun(root, mp, depth, 1);
        return recFun(root);
    }
};