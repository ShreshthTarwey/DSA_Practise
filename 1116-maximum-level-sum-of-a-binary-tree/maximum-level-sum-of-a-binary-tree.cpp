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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>sums;
        vector<int>temp;
        int sum = 0;
        while(!q.empty()){
            sum = 0;
            int size = q.size();
            for(int i=0;i<size;i++){
                // temp.push_back(q.top());
                
                TreeNode* front=q.front();
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
                sum+=front->val;
                q.pop();
            }
            sums.push_back(sum);
        }
        auto it = max_element(sums.begin(), sums.end());
        return distance(sums.begin(), it) + 1;
    }
};