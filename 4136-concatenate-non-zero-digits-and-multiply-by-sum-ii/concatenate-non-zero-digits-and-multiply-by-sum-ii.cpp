class Solution {
public:
    const int MOD = 1e9+7;
    typedef long long ll;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<ll>digitSum(n, 0);//To store digit sum
        vector<ll>numberUpto(n, 0);//Number upto
        vector<ll>nonZeroCount(n, 0);//Non Zero numbers count
        vector<ll>powerK(n+1, 0); //Gives 10^i
        powerK[0] = 1;
        for(int i=1;i<=n;i++){
            powerK[i] = (powerK[i-1] * 10) % MOD;
        }
        //Calculating DigitSum
        digitSum[0] = s[0]-'0';
        for(int i=1;i<n;i++){
            digitSum[i] += digitSum[i-1] + s[i]-'0';
        }
        //Calculating numberUpto
        numberUpto[0] = s[0]-'0';
        for(int i=1;i<n;i++){
            int digit = s[i] - '0';
            if(digit != 0)
                numberUpto[i] = ((numberUpto[i-1] * 10) + digit)%MOD;
            else
                numberUpto[i] = numberUpto[i-1];
        }
        //NonZeroNumbers Count
        nonZeroCount[0] = (s[0] - '0' > 0 ? 1 : 0);
        for(int i=1;i<n;i++){
            nonZeroCount[i] += nonZeroCount[i-1] + (s[i] - '0' > 0 ? 1 : 0);
        }

        int q = queries.size();
        vector<int>result;
        for(int i=0;i<q;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            long long sum = digitSum[r];
            if(l-1>=0){
                sum -= digitSum[l-1];
            }
            int k = nonZeroCount[r];
            if(l-1>=0){
                k -= nonZeroCount[l-1];
            }
            //Finding x
            long long x = numberUpto[r];
            if(l-1>=0){
                x = (x - (numberUpto[l-1] * powerK[k])%MOD + MOD)%MOD;
            }
            //Finding Answer
            long long num = (x*sum)%MOD;
            result.push_back(num);
        }
        return result;
    }
};