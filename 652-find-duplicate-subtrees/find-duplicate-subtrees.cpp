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
    bool isIdentical(TreeNode* a, TreeNode* b){
        if(!a && !b) return true;
        if(!a || !b) return false;

        return (a->val == b->val) && isIdentical(a->left, b->left) && isIdentical(a->right, b->right);
    }
    vector<TreeNode*> bruteForce(TreeNode* root){
        vector<TreeNode*>nodes;
        if(!root) return nodes;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            nodes.push_back(q.front());
            TreeNode* node = q.front();
            q.pop();
            TreeNode* left = node->left;
            TreeNode* right = node->right;
            if(left) q.push(left);
            if(right) q.push(right);
        }
        int n = nodes.size();
        vector<bool>visited(n, false);
        vector<TreeNode*>result;
        for(int i=0;i<n;i++){
            if(visited[i]) continue;

            bool duplicateFound = false;
            for(int j=i+1;j<n;j++){
                if(isIdentical(nodes[i], nodes[j])){
                    visited[j] = true;
                    duplicateFound = true;
                }
            }
            if(duplicateFound){
                result.push_back(nodes[i]);
            }
        }
        return result;
    }
    string getSubtreeString(TreeNode* root, unordered_map<string, int>& mp, vector<TreeNode*> &res){
        if(!root) return "N";
        string s = to_string(root->val) + ", " + getSubtreeString(root->left, mp, res) + ", " + getSubtreeString(root->right, mp, res) + ", ";

        if(mp[s] == 1){
            res.push_back(root);
        }
        mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // return bruteForce(root); //TLE O(N^3)
        unordered_map<string, int>mp;
        vector<TreeNode*>res;
        getSubtreeString(root, mp, res);
        return res;
    }
};