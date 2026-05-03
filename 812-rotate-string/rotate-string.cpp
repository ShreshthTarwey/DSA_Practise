class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.length() != s.length()) return false;
        string str = s+s;
        return (str.find(goal) == string::npos ? false : true);
    }
};