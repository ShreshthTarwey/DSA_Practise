class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string result = "";
        string temp = "";
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                count++;
            }
            else{
                count--;
            }
            temp += s[i];
            if(count == 0){
                temp.erase(0, 1);
                temp.pop_back();
                result += temp;
                temp = "";
            }
        }
        return result;
    }
};