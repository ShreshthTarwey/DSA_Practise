class Solution {
public:
    void fun(vector<string>& ans, string s, int n) {
        // Base Case
        if (s.length() == n) {
            ans.push_back(s);
            return;
        }
        fun(ans, s + '1', n);
        // int index = s.length() - 1;

        if(s.empty() || s.back()!='0'){
            fun(ans, s+'0', n);
        }
        
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string s = "";
        fun(ans, s, n);
        return ans;
    }
};