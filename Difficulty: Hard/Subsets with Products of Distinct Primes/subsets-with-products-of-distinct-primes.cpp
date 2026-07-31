class Solution {
public:
    int countSubsets(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        vector<int> cnt(31, 0);

        for (int x : arr) cnt[x]++;

        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

        vector<int> mask(31, -1);

        for (int x = 2; x <= 30; x++) {
            int t = x;
            int m = 0;
            bool ok = true;

            for (int i = 0; i < 10; i++) {
                int p = primes[i];
                int c = 0;

                while (t % p == 0) {
                    t /= p;
                    c++;
                }

                if (c > 1) {
                    ok = false;
                    break;
                }

                if (c == 1)
                    m |= (1 << i);
            }

            if (ok)
                mask[x] = m;
        }

        vector<long long> dp(1 << 10, 0);
        dp[0] = 1;

        for (int x = 2; x <= 30; x++) {
            if (cnt[x] == 0 || mask[x] == -1) continue;

            int m = mask[x];

            for (int s = (1 << 10) - 1; s >= 0; s--) {
                if ((s & m) == 0) {
                    dp[s | m] =
                        (dp[s | m] + dp[s] * cnt[x]) % MOD;
                }
            }
        }

        long long ans = 0;
        for (int s = 1; s < (1 << 10); s++)
            ans = (ans + dp[s]) % MOD;

        long long pow2 = 1;
        for (int i = 0; i < cnt[1]; i++)
            pow2 = (pow2 * 2) % MOD;

        ans = (ans * pow2) % MOD;

        return (int)ans;
    }
};