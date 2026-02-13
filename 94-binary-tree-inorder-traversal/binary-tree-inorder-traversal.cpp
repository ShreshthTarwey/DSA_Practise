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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int>ans;
        while(curr){
            //Does Curr have a left child
            //Find the IP, Inorder Predecesor
            if(curr->left){
                TreeNode* IP = curr->left;
                while(IP->right  && IP->right!=curr){
                    IP = IP->right;
                }
                if(IP->right == NULL){
                    //Create a sudo LINK
                    IP->right = curr;
                    curr = curr->left;
                }
                else{
                    //Print the curr and delete link and move to right
                    ans.push_back(curr->val);
                    IP->right = NULL;
                    curr = curr->right;
                }
            }
            else{
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
};