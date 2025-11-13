class Solution {
public:
    void fun(vector<string>& ans, string s, int n) {
        // Base Case
        if (s.length() == n) {
            ans.push_back(s);
            return;
        }
        s.push_back('1');
        fun(ans, s, n);
        s.pop_back();
        // int index = s.length() - 1;

        if(s.empty() || s.back()!='0'){
            s.push_back('0');
            fun(ans, s, n);
            s.pop_back();
        }
        
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string s = "";
        fun(ans, s, n);
        return ans;
    }
};