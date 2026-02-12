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
  
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val == key){
            //Case 1:  Target node is leaf node
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            //Case 2: Left child only
            if(!root->right){
                auto it = root->left;
                delete root;
                return it;
            }
            //Case 3: Right Child only
            if(!root->left){
                auto it = root->right;
                delete root;
                return it;
            }

            //Case 4: Both Child exist
            //Find the greatest element from left
            TreeNode* parent = root;
            TreeNode* child = root->left;
            while(child->right){
                parent = child;
                child = child->right;
            }

            if(root != parent){
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
            else{
                // child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
        }
        else if(root->val>key){
            root->left = deleteNode(root->left, key);
        }
        else{
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};