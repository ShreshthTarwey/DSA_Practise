class Solution {
public:
    bool checkDivisibility(int n) {
        long long digitSum = 0;
        long long digitProduct = 1;
        int temp = n;
        while(temp){
            digitSum += temp%10;
            digitProduct *= temp%10;
            temp /= 10;
        }
        
        return n%(digitSum+digitProduct) == 0;
    }
};