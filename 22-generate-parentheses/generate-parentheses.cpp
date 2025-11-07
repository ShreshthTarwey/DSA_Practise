class Solution {
public:
    void solve(vector<string>& ans, string out, int open, int close, int n){
        //Base Case
        if(open + close == 2*n){
            ans.push_back(out);
            return;
        }

        //Pushing open first
        if(open<n){
            solve(ans, out+"(", open+1, close, n);
        }

        //Pushing close if < open

        if(close<open){
            solve(ans, out+")", open, close+1, n);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string out = "";
        solve(ans, out, 0, 0, n);
        return ans;
    }
};