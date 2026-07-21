class Solution {
public:
    string reverseWords(string s) {
        vector<string>ans;
        string word = "";
        int i=0;
        while(i<s.length()){
            while(i<s.length() && s[i]==' '){
                i++;
            }
            while(i<s.length() && s[i]!=' '){
                word += s[i];
                i++;
            }
            if(word.empty()){
                break;
            }
            ans.push_back(word);
            word = "";
        }
        reverse(ans.begin(), ans.end());
        string result = "";
        for(int i=0;i<ans.size();i++){
            result += ans[i];
            if(i != ans.size()-1)
                result += " ";
        }
        return result;
    }
};