class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        int n = queries.size();
        int m = dictionary.size();
        for(int i=0;i<n;i++){
            string str1 = queries[i];
            for(int j=0;j<m;j++){
                string str2 = dictionary[j];
                int diff = 0;
                for(int k=0;k<str1.length();k++){
                    if(str1[k] != str2[k]){
                        diff++;
                    }
                }
                if(diff<=2){
                    ans.push_back(str1);
                    break;
                }
            }
        }
        return ans;
    }
};