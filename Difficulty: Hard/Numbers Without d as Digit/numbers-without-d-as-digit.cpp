class Solution {
public:
    long long dp[12][2][2];
    string s;
    int d;

    long long countWithout(int pos, int tight, int started) {
        if (pos == s.size())
            return started ? 1 : 0;

        if (dp[pos][tight][started] != -1)
            return dp[pos][tight][started];

        int limit = tight ? s[pos] - '0' : 9;
        long long ans = 0;

        for (int x = 0; x <= limit; x++) {

            // Ignore leading zeros
            // But don't allow digit d in the actual number
            if (x == d && (started || x != 0))
                continue;

            int newStarted = started || (x != 0);

            int newTight = tight && (x == s[pos] - '0');

            ans += countWithout(pos + 1, newTight, newStarted);
        }

        return dp[pos][tight][started] = ans;
    }

    long long countWithout(long long n, int d) {
        if (n <= 0)
            return 0;

        s = to_string(n);
        this->d = d;

        memset(dp, -1, sizeof(dp));

        return countWithout(0, 1, 0);
    }
};