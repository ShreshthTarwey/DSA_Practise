class Fancy {
public:
    typedef long long ll;
    vector<ll>seq;
    ll mul, add;
    ll M = 1e9 + 7;
    Fancy() {
        mul = 1;
        add = 0;
    }
    ll power(long long a, long long b){
        long long ans = 1;
        a = a%M;
        while(b>0){
            if(b&1){
                //Odd
                ans = (ans * a)%M;
            }
            a = (a*a)%M;
            b/=2;
        }
        return ans;
    }
    void append(int val) {
        ll x = (val-add + M)%M * power(mul, M-2)%M;
        seq.push_back(x);
    }
    
    void addAll(int inc) {
        add = (add + inc)%M;
    }
    
    void multAll(int m) {
        mul = (m*mul)%M;
        add = (add * m)%M;
    }
    
    int getIndex(int idx) {
        if(idx>=seq.size()){
            return -1;
        }
        ll x = seq[idx];
        return ((x*mul) + add) % M;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */