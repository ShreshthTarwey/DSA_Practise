class Solution {
public:
    long long fact(long long n){
        if(n<=1) return 1;
        return n * fact(n-1);
    }
    bool isDigitorialPermutation(int n) {
        long long sum = 0;
        string num = to_string(n);
        for(char c: num){
            sum += fact(c - '0');
        }
        string original = to_string(n);
        string newNum = to_string(sum);
        unordered_map<char, int>mp1,mp2;
        for(char c: original){
            mp1[c]++;
        }
        for(char c: newNum){
            mp2[c]++;
        }
        return mp1 == mp2;
    }
};