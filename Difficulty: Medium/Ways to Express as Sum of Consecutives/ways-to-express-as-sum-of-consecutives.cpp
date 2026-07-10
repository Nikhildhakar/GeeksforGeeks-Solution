class Solution {
  public:
    int getCount(int n) {
        int ans = 0;

        for (long long k = 2; k * (k + 1) / 2 <= n; k++) {
            long long temp = n - k * (k - 1) / 2;

            if (temp > 0 && temp % k == 0)
                ans++;
        }

        return ans;
    }
};