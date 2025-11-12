class Solution {
public:
    double fun(double x, int e){
        if(e==0) return 1.0;
        double half = fun(x, e/2);
        if(e%2==0){
            return half*half;
        }
        else{
            return x*half*half;
        }
    }
    
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        long long e = n;
        if(e<0){
            e = -1*e;
        }
        double ans = fun(x, e);
        if(n>0) return ans;
        else return 1/ans;
    }
};