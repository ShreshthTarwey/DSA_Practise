class Solution {
public:
    bool isPrime(int n){
        if(n<=1) return false;
        if(n<=3) return true;
        if(n%2==0 || n%3==0) return false;
        for(int i=5;i*i<=n;i+=6){
            if((n%i)==0 || n%(i+2)==0) return false;
        }
        return true;
    }
    bool primeSubOperation(vector<int>& nums) {
        int prev = 0,i;
        for(int num : nums){
            int maxn = num-prev;
            int maxprime = 0;
            for(int i=maxn-1;i>=2;i--){
                if(isPrime(i)){
                    maxprime = i;
                    break;
                }
            }
            if(num-maxprime <= prev) return false;
            prev = num-maxprime;
        }
        return true;
    }
};