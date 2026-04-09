class Solution {
public:
    const int MOD = 1e9 + 7;
    long long power(long long a, long long b){
        long long res = 1;
        while(b){
            if(b&1){
                res = (res*a) % MOD;
            }
            a = (a * a)%MOD;
            b >>= 1;
        }
        return res;
    }
    long long modInverse(long long x){
        return power(x, MOD-2);
    }
    void solve(vector<int>& diff, int k, vector<vector<int>>& queries){
        int n = diff.size();
        for(auto &it: queries){
            int l = it[0];
            int r = it[1];
            int v = it[3];
            int steps = (r-l)/k;
            int next = l + (steps+1)*k;
            diff[l] = ((long long)diff[l]*v) % MOD;
            if(next<n){
                long long inv = modInverse(v);
                diff[next] = (diff[next] * inv)%MOD;
            }
        }
         //now creating cummulative array
        for(int i=0;i<n;i++){
            if(i-k>=0){
                diff[i] = ((long long)diff[i]*diff[i-k]) % MOD;
            }
        }
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        unordered_map<int, vector<vector<int>>>mp;
        int n = nums.size();
        for(auto &query: queries){
            int l = query[0];
            int r = query[1];
            int k = query[2];
            int v = query[3];
            if(k>=ceil(sqrt(n))){
                //Apply direct brute force cause it will not go beyond O(q.sqrt(n))
                for(int i=l;i<=r;i+=k){
                    nums[i] = ((long long)nums[i]*v)%MOD;
                }
            }
            else{
                mp[k].push_back(query);
            }
        }
        //Now processing the queries in map
        for(auto it: mp){
            vector<int>diff(n, 1);
            solve(diff,it.first, it.second);
            //Multiplying it to nums
            for(int i=0;i<n;i++){
                nums[i] = ((long long)nums[i] * diff[i]) % MOD;
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans ^= nums[i];
        }
        return ans;
    }
};