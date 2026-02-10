class Solution {
public:
    bool isPalindrome(string &s){
        int i=0;
        int j = s.length()-1;
        while(i<=j){
            if(s[i++] != s[j--]){
                return false;
            }
        }
        return true;
    }
    void recFun(string &s, int idx, vector<vector<string>>& ans, vector<string>& temp){
        if(idx>=s.length()){
            if(!temp.empty()){
                ans.push_back(temp);
                // temp.clear();
            }
            return;
        }

        string tempStr = "";
        for(int i=idx;i<s.length();i++){
            tempStr+=s[i];
            if(isPalindrome(tempStr)){
                temp.push_back(tempStr);
                recFun(s, i+1, ans, temp);
                temp.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        vector<vector<string>>ans;
        recFun(s, 0, ans, temp);
        return ans;
    }
};