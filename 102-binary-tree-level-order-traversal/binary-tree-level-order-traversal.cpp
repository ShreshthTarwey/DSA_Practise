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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        if(!root) return ans;
        // ans.push_back({root->val});
        while(!q.empty()){
            // TreeNode* temp = q.front();
            int lvl = q.size();
            vector<int>temp;
            for(int i=0;i<lvl;i++){
                TreeNode* temp2 = q.front();
                q.pop();
                temp.push_back(temp2->val);
                if(temp2->left) q.push(temp2->left);
                if(temp2->right) q.push(temp2->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};