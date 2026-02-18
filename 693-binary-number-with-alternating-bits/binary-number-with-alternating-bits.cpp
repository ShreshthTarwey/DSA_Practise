class Solution {
public:
    bool hasAlternatingBits(int n) {
        // int prevBit = -1;
        // for(int i=0;i<32 && n;i++){
        //     int currBit = (n & 1);
        //     if(prevBit == currBit) return false;
        //     prevBit = currBit;
        //     n>>=1;
        // }
        // return true;
        long long n2 = (n>>1);
        long long num = n ^ n2;
        return ((num & (num+1))==0 ? true : false);
    }
};