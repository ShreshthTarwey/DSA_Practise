class Solution {
public:
    bool isPrime(int n){
        for(int i=2;i<n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int naiveApproach(int n){
        if(n<=1) return 0;
        int count = 0;
        for(int i=2;i<n;i++){
            if(isPrime(i)) count++;
        }
        return count;
    }
    int sieveOfEratosthenes(int n){ //T.C-> O(nloglogn)
        if(n<=1) return 0;
        vector<bool>primes(n,true);
        primes[0] = primes[1] = false;
        int count = 0;
        for(int i=2;i<n;i++){
            if(primes[i]){
                count++;
                int j = i*2;
                while(j<n){
                    primes[j] = false;
                    j+=i;
                }
            }
        }
        return count;
    }
    int sieveOfAtkins(int n){
        if(n<=2) return 0;
        vector<bool> prime(n, false);
        prime[2] = prime[3] = true;
        for(int x=1;x*x<=n;x++){
            for(int y=1;y*y<=n;y++){
                int num = 4*x*x + y*y;
                if(num<n && (num%12== 1 || num%12==5)){
                    prime[num] = !prime[num];
                }
                num = 3*x*x + y*y;
                if(num<n && (num%12==7)){
                    prime[num] = !prime[num];
                }
                num = 3*x*x - y*y;
                if(x>y && num<n && num%12==11) prime[num] = !prime[num];

            }
        }
        for(int i=5;i*i<=n;i++){
            if(prime[i]){
                for(int j=i*i;j<n;j+=i*i){
                    prime[j] = false;
                }
            }
        }
        int count = 0;
        for(int i=1;i<prime.size();i++){
            if(prime[i]){
                count++;
            }
        }
        return count;
    }
    int countPrimes(int n) {
        // return naiveApproach(n);//TC-> O(n^2)
        // return sieveOfEratosthenes(n);
        return sieveOfAtkins(n);
    }
};