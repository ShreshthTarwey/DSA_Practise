class Solution {
public:
    int reverse(int n){
        int res = 0;
        while(n){
            int digit = n%10;
            res = res*10 + digit;
            n/=10;
        }
        return res;
    }
    int mirrorDistance(int n) {
        return abs(n - reverse(n));
    }
};