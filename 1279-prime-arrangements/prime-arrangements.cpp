class Solution {
public:
    bool isPrime(int n){
        if(n<=1) return false;
        if(n<=3) return true;
        if(n%2==0 || n%3==0) return false;
        for(int i=5;i*i<=n;i+=6){
            if(n%i==0 || n%(i+2)==0){
                return false;
            }
        }
        return true;
    }

    int countPrimes(int n){
        int count = 0;
        for(int i=1;i<=n;i++){
            if(isPrime(i)) count++;
        }
        return count;
    }
    long long fact(long long n, long long MOD) {
    long long result = 1;
    for(long long i = 2; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

    int numPrimeArrangements(int n) {
        const long long MOD = 1000000007LL;
        int count = countPrimes(n);
        int ncount = n-count;
        return (fact(count, MOD) * fact(ncount, MOD) )% (MOD);
    }

};