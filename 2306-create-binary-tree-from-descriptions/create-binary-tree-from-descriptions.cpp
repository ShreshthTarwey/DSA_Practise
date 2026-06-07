/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, int> l, r;
        unordered_set<int> st;
        for (int i = 0; i < descriptions.size(); i++) {
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            bool isLeft = descriptions[i][2];
            if (isLeft) {
                l[parent] = child;
            } else {

                r[parent] = child;
            }
            st.insert(parent);
        }
        // find the root node
        for (auto& it : l) {
            if (st.contains(it.second)) {
                st.erase(it.second);
            }
        }
        for (auto& it : r) {
            if (st.contains(it.second)) {
                st.erase(it.second);
            }
        }
        int root1 = *st.begin();
        TreeNode* root = new TreeNode(root1);
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(l.count(node->val)){
                node->left = new TreeNode(l[node->val]);
                q.push(node->left);
            }
            if(r.count(node->val)){
                node->right = new TreeNode(r[node->val]);
                q.push(node->right);
            }
        }
        return root;
    }
};