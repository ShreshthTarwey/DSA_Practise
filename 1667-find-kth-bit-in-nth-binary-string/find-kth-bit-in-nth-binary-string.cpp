class Solution {
public:
    string rever(string str){
        int i=0;
        int j = str.length()-1;
        while(i<j){
            swap(str[i], str[j]);
            i++;j--;
        }
        return str;
    }
    string invert(string str){
        for(int i=0;i<str.length();i++){
            if(str[i]=='0'){
                str[i] = '1';
            }
            else{
                str[i] = '0';
            }
        }
        return str;
    }
    void recFun(string &str, int num, int n){
        if(num==n) return;
        str = str + "1" + (rever(invert(str)));
        recFun(str, num+1, n);
    }
    char findKthBit(int n, int k) {
        string res = "0";
        recFun(res,0, n);
        return res[k-1];
    }
};