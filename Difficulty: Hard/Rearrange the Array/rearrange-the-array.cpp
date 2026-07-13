class Solution {
  public:
    long long gcd(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    int minOperations(vector<int> &b) {
        const int MOD = 1000000007;
        int n = b.size();
        vector<bool> vis(n, false);

        long long ans = 1;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int len = 0;
                int cur = i;

                while (!vis[cur]) {
                    vis[cur] = true;
                    cur = b[cur] - 1;   // 1-based to 0-based
                    len++;
                }

                ans = (ans / gcd(ans, len)) * len;
                ans %= MOD;
            }
        }

        return (int)ans;
    }
};