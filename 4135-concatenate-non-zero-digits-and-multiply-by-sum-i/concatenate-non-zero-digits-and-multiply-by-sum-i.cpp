class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long temp = 0;
        string str = to_string(n);
        long long sum = 0;
        for(auto &it: str){
            int digit = it-'0';
            if(digit){
                x = x*10 + digit;
            }
            sum += digit;
        }
        return sum * x;
    }
};