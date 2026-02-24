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
    int process(string str){
        int p = 0;
        int num = 0;
        for(int i=str.length()-1;i>=0;i--){
            if(str[i] == '1'){
                num += pow(2, p);
            }
            p++;
        }
        return num;
    }
    int recFun(TreeNode* root, string str){
        if(!root) return 0;
        if(!root->left && !root->right){
            int ans = process(str + to_string(root->val));
            return ans;
        }
        cout<<str<<endl;
        //Left
        int left = recFun(root->left, str+ to_string((root->val)));
        int right = recFun(root->right, str + to_string(root->val));

        return left + right;
    }
    int sumRootToLeaf(TreeNode* root) {
        string res = "";
        return recFun(root, res);
    }
};