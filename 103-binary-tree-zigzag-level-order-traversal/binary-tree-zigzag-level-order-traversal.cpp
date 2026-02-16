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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        bool rev = false;
        while(!q.empty()){
            int size = q.size();
            vector<int>temp;
            for(int i=0;i<size;i++){
                TreeNode* temp2 = q.front();
                q.pop();
                if(temp2->left) q.push(temp2->left);
                if(temp2->right) q.push(temp2->right);
                temp.push_back(temp2->val);
            }
            if(rev){
                reverse(temp.begin(), temp.end());
            }
            // else{
                rev = !rev;
            // }
            ans.push_back(temp);
        }
        return ans;
    }
};