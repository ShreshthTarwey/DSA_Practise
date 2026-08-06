class Solution {
public:
    int product(int n){
        int p = 1;
        while(n){
            int digit = n%10;
            p *= digit;
            n/=10;
        }
        return p;
    }
    int smallestNumber(int n, int t) {
        while(true){
            int candidate = product(n);
            if(candidate%t == 0){
                return n;
            }
            // candidate++;
            n++;
        }
        return -1;
    }
};