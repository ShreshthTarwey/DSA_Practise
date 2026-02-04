class Solution {
public:
    string recFun(string s, int &i){
        if(i>=s.length()) return "";
        // int index = 0;
        string res = "";
        
        while(i<s.length() && s[i]!=']'){
            if(!isdigit(s[i])) res+=s[i++];
            else{
                int num = 0;
                while(isdigit(s[i]))
                    num = num*10 + s[i++]-'0';
                i++;
                //Start decoding string
                string decoded = recFun(s, i);
                //Skipping ]
                i++;
                while(num--){
                    res+=decoded;
                }
            }
            // i++;
        }
        return res;
    }
    string decodeString(string s) {
        int index = 0;
        return recFun(s,index);
    }
};