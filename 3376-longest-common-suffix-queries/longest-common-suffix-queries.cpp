class Solution {
public:
    struct Trie{
        int idx;
        // vector<Trie*> arr = vector<Trie*>(26, NULL);
        Trie* arr[26];
        ~Trie() {
            for (int i = 0; i < 26; i++) {
                delete arr[i];
            }
        }
    };
    Trie* getNode(int i){
        Trie* temp = new Trie();
        temp->idx = i;
        for(int i=0;i<26;i++){
            temp->arr[i] = NULL;
        }
        return temp;
    }
    void insertTrie(Trie* root, int i, vector<string>& wordsContainer){
        string &word = wordsContainer[i];
        int n = word.length();
        for(int j=n-1;j>=0;j--){
            char ch = word[j];
            int char_idx = ch - 'a';
            if(root->arr[char_idx] == NULL){
                root->arr[char_idx] = getNode(i);
            }
            root = root->arr[char_idx];
            if(wordsContainer[root->idx].length() > n){
                root->idx = i;
            }
        }
    }
    int searchTrie(Trie* root, string &str){
        int result_idx = root->idx;
        int n  = str.length();
        for(int i=n-1;i>=0;i--){
            int ch_idx = str[i] - 'a';
            root = root->arr[ch_idx];
            if(root == NULL){
                return result_idx;
            }
            result_idx = root->idx;
        }
        return result_idx;
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n = wordsContainer.size();
        int m = wordsQuery.size();
        vector<int>res(m);
        Trie* root = getNode(0);
        for(int i=0;i<n;i++){
            int idx = root->idx;
            if(wordsContainer[idx].length()>wordsContainer[i].length()){
                root->idx = i;
            }
            insertTrie(root, i, wordsContainer);
        }
        for(int i=0;i<m;i++){
            res[i] = searchTrie(root, wordsQuery[i]);
        }
        delete root;
        return res;
    }
};