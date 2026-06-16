class Solution {
public:
    string processStr(string s) {
        string res = "";
        int index = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]>='a' && s[i]<='z'){
                res.push_back(s[i]);
                index++;
            }
            else if(s[i]=='*'){
                if(index>0){
                    res.pop_back();
                    index--;
                }
            }
            else if(s[i]=='#'){
                if(index>0){
                    res+=res;
                    index = res.length();
                }
            }
            else if(s[i]=='%'){
                reverse(res.begin(),res.end());
            }
        }
        return res;
    }
};