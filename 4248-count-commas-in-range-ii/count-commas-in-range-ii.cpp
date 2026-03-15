class Solution {
public:
    long long countCommas(long long n) {
        long long threashold = 1000;
        long long commas = 0;
        while(threashold <= n){
            commas += (n - threashold + 1);

            if (threashold > 1e15) break;
            threashold *= 1000;
        }
        return commas;
    }
};