class Solution {
public:
    bool isPrime(int n){
        if(n<=1) return false;
        if(n<=3) return true;
        if(n%2==0 || n%3==0) return false;
        
        for(int i=5;i*i<=n;i+=6){
            if((n%i)==0 || (n%(i+2)==0)){
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(int n){
        int reverse = 0;
        int temp = n;
        while(temp!=0){
            int digit = temp%10;
            reverse  = reverse*10 + digit;
            temp/=10;
        }
        return reverse == n;
    }
    int primePalindrome(int n) {
        // BruteForce
        
        int num = n;
        while(true){
            if (n >= 10000000 && n <= 100000000)
                n = 100000000;
            if(isPalindrome(n) && isPrime(n)){
                return n;
            }
            
            n++;
        }
        return -1;
    }
};