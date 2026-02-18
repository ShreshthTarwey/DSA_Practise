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
        // int index = 0;
        // return recFun(s, index); ------------------> Recursive Method ---------------------

        // --------------------Stack Method ---------------------------------------------

        stack<long long>st;
        long long result = 0;
            int sign  = 1;
        for(int i=0;i<s.length();i++){
            char c = s[i];
            if(c == '('){
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }
            else if(c == ')'){
                if(!st.empty()){
                    int sign = st.top(); st.pop();
                    long long prevResult = st.top(); st.pop();
                    // st.pop();
                    result = prevResult + (result * sign);
                    // st.push(prevResult + (result * sign));
                }
            }
            else if(c == '+'){
                sign = 1;
            }
            else if(c == '-'){
                sign = -1;
            }
            else if(isdigit(c)){
                long long num = 0;
                while(i<s.length() && isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                result += (sign * num);
            }
        }
        return result;

    }
};