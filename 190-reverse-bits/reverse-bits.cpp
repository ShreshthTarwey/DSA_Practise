class Solution {
public:
    int reverseBits(int n) {
        int result = 0;
        for(int i=0;i<32;i++){
            int digit = n&1;
            result = (result<<1) | digit;
            n>>=1;
        }
        return result;
    }
};