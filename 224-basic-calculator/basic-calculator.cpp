class Solution {
public:
    int recFun(string &s, int &idx){
        if(idx>=s.length()) return 0;
        int sign = 1;
        long long sum = 0;
        while(idx<s.length()){
            char c = s[idx];

            if(isdigit(c)){
                long long num = 0;
                while(idx<s.length() && isdigit(s[idx])){
                    num = num * 10 + (s[idx] - '0');
                    idx++;
                }
                idx--;
                sum += (num * sign);
            }
            else if(c == '('){
                idx++;
                sum += (recFun(s, idx) * sign);
            }
            else if(c == ')'){
                // idx++;
                return sum;
            }
            else if(c == '+'){
                sign = 1;
            }
            else if(c == '-') {
                sign = -1;
            }
            idx++;
        }
        return sum;
    }
    int calculate(string s) {
        int index = 0;
        return recFun(s, index);
    }
};