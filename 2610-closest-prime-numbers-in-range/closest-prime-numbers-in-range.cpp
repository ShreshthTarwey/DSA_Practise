class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int n = sqrt(right);
        vector<bool> isPrime(n+1,true);
        isPrime[0] = isPrime[1] = false;

        for(int i=2;i*i<=n;i++){
            if(isPrime[i]){
                for(int j=i*i;j<=n;j+=i){
                    isPrime[j] = false;
                }
            }
        }
        vector<int> prime;
        for(int i=0;i<=n;i++){
            if(isPrime[i]) prime.push_back(i);
        }
        int size = right-left+1;
        vector<bool>ans (size,true);

        for(auto p:prime){
            long long start =  max(1LL * p * p, ((left + p - 1) / p) * 1LL * p);
            for(long long j=start;j<=right;j+=p){
                if(j>=left && j<=right){
                    ans[j-left] = false;
                }
            }
        }
        if(left==1) ans[0] = false;
        vector<int> primes;
        for (int i = 0; i < size; i++) {
            if (ans[i]) primes.push_back(i + left);
        }
        
        vector<int> fin(2, -1);
        int minDiff = INT_MAX;
        if(ans.size()<2) return {-1,-1};
        for(int i=0;i+1<primes.size();i++){
            int diff = primes[i+1] - primes[i];
            if(diff<minDiff){
                minDiff = diff;
                fin = {primes[i], primes[i+1]};
            }
        }
        return fin;

    }
};