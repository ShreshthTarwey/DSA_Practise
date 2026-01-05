class Solution {
public:
    void sieve(int n, vector<int>& primes){
        vector<int>isPrime(n+1, true);
        isPrime[0] = isPrime[1] = false;
        for(int i=2;i*i<=n;i++){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j] = false;
            }
        }
        for(int i=0;i<isPrime.size();i++){
            if(isPrime[i]){
                primes.push_back(i);
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        vector<int>primes;
        sieve(1000, primes);
        int prev = 0;
        for(int i=0;i<nums.size();i++){
            // int diff = nums[i] - prev;
            for(int j=primes.size()-1;j>=0;j--){
                if(nums[i]-primes[j]>prev){
                    nums[i] = nums[i] - primes[j];
                    // prev = nums[i];
                    break;
                }
            }
            if(nums[i]<=prev) return false;
            prev = nums[i];
        }
        return true;
    }
};