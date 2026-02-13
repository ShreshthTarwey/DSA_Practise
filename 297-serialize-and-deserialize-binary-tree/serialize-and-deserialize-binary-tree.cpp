/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            ans+= (temp == NULL? "N," : to_string(temp->val) + ",");
            if(temp){
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;
        vector<string>vals;
        string curr = "";
        for(auto it: data){
            if(it == ','){
                vals.push_back(curr);
                curr="";
            }
            else{
                curr+=it;
            }
        }

        TreeNode* root = new TreeNode(stoi(vals[0]));
        queue<TreeNode*>q;
        q.push(root);

        int i = 1;
        while(!q.empty() && i<vals.size()){
            TreeNode* parent = q.front();
            q.pop();
            
            //Left Child
            if(vals[i] != "N"){
                TreeNode* leftChild = new TreeNode(stoi(vals[i]));
                parent->left = leftChild;
                q.push(leftChild);
            }
            i++;
            //Right Child
            if(vals[i] != "N"){
                TreeNode* rightChild = new TreeNode(stoi(vals[i]));
                parent->right = rightChild;
                q.push(rightChild);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));