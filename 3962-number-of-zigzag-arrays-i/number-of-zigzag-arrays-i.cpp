class Solution {
public:
    const long long mod = 1000000007;

    int zigZagArrays(int n, int l, int r)
    {
        vector<long long> dp(r + 1, 1);

        for(int i = 1; i < n; i++)
        {
           // vector<long long> old = dp;

            if(i % 2 != 0) // increase
            {
                vector<long long> suffix(r + 2, 0);

                for(int k = r; k >= l; k--)   /// storing  sum
                {
                    suffix[k] = (suffix[k + 1] + dp[k]) % mod;
                }

                for(int k = l; k <= r; k++)
                {
                    dp[k] = suffix[k + 1];
                }
            }
            else // decrease
            {
                vector<long long> prefix(r + 1, 0);

                

                for(int k = l; k <= r; k++)
                {
                    prefix[k] = (prefix[k - 1] + dp[k]) % mod;
                }

               

                for(int k = l ; k <= r; k++)
                {
                    dp[k] = prefix[k - 1];
                }
            }
        }

        long long ans = 0;

        for(int i = l; i <= r; i++)
        {
            ans = (ans + dp[i]) % mod;
        }

        return (ans * 2) % mod;
    }
};