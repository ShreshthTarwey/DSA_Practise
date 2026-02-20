class Solution {
public:
    string recFun(string &s){
        int start = 0;
        vector<string>specials;
        int sum = 0;
        for(int i=0;i<s.length();i++){
            sum+= (s[i]=='0'? -1 : 1);
            if(sum==0){
                string str = s.substr(start+1, i-start-1);
                specials.push_back("1" + recFun(str) + "0");
                start = i+1;
            }
        }
        sort(specials.begin(), specials.end(), greater<string>());
        string result = "";
        for(auto &str: specials){
            result+=str;
        }
        return result;
    }
    string makeLargestSpecial(string s) {
        return recFun(s);
    }
};