class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // int sumOdd = 0;
        // int sumEven = 0;
        // int even = 2;
        // int odd = 1;
        // for(int i=0;i<n;i++){
        //     even+=2;
        //     odd+=2;
        //     sumOdd+=odd;
        //     sumEven+=even;
        // }
        // // cout<<sumOdd<<" "<<sumEven<<endl;
        int sumE = n*n;
        int evenS = n*(n+1);
        return gcd(sumE, evenS);

    }
};