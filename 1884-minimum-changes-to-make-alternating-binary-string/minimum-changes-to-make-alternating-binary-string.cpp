class Solution {
public:
    int minOperations(string s) {
        int op1 = 0; //0-1
        int op2 = 0;//1-0
        char want1 = '0';
        char want2 = '1';
        for(char c: s){
            if(want1 != c){
                op1++;
            }
            if(want2 != c){
                op2++;
            }
            want1 = (want1=='0' ? '1' : '0');
            want2 = (want2 == '0'? '1':'0');
        }
        return min(op1, op2);

    }
};