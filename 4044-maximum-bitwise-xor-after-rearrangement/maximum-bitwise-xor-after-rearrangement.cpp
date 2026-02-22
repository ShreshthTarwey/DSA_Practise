class Solution {
public:
    string maximumXor(string s, string t) {
        int oneCount = 0;
        int zeroCount = 0;
        for(char c: t){
            if(c == '0'){
                zeroCount++;
            }
            else{
                oneCount++;
            }
        }
        string res = "";
        for(char c: s){
            if(c=='0'){
                if(oneCount){
                    res+='1';
                    oneCount--;
                }
                else{
                    res+='0';
                }
            }
            else{
                if(zeroCount){
                    res+='1';
                    zeroCount--;
                }
                else{
                    res+='0';
                }
            }
        }
        return res;
    }
};