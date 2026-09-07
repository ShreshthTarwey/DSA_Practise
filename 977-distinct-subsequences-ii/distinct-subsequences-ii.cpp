class Solution {
public:
    int dp[2001];
    const int MOD = 1e9 + 7;
    vector<int> prev;
    int solve(int n) {
        if (n == 0) {
            return 1;
        }
        if (dp[n] != -1)
            return dp[n];
        long long total = 2LL * solve(n - 1);

        int duplicates = 0;

        if (prev[n] != 0) {
            duplicates = solve(prev[n] - 1);
        }

        total = (total - duplicates + MOD) % MOD;
        // total = (total - duplicates +)
        return dp[n] = total % MOD;
    }
    int distinctSubseqII(string s) {
        int n = s.length();
        prev.resize(n + 1);
        memset(dp, -1, sizeof(dp));
        vector<int> lastSeen(26);
        for (int i = 1; i <= n; i++) {
            int idx = s[i - 1] - 'a';
            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }
        return (solve(n) - 1 + MOD)%MOD;
    }
};