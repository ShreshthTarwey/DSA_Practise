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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<tuple<TreeNode*, int, int>>q;
        map<int, vector<pair<int,int>>>mp;
        q.push({root, 0, 0});
        while(!q.empty()){
            auto [node, col, row] = q.front();
            q.pop();

            if(node->left){
                q.push({node->left, col-1, row+1});
            }
            if(node->right){
                q.push({node->right, col+1, row+1});
            }
            mp[col].push_back({row, node->val});
        }
        vector<vector<int>>ans;
        for(auto &p : mp){
            sort(p.second.begin(), p.second.end());
            vector<int>temp;
            for(auto &it: p.second){
                temp.push_back(it.second);
            }
            ans.push_back(temp);
        }
        return ans; 
    }
};