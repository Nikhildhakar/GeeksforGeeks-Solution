class Solution {
public:

    int getSum(vector<vector<int>>& pref,
               int r1, int c1, int r2, int c2) {

        return pref[r2 + 1][c2 + 1]
             - pref[r1][c2 + 1]
             - pref[r2 + 1][c1]
             + pref[r1][c1];
    }

    vector<int> largestSquare(vector<vector<int>>& mat,
                                  vector<vector<int>>& queries,
                                  int k) {

        int n = mat.size();
        int m = mat[0].size();

        // Prefix sum
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pref[i + 1][j + 1] =
                    mat[i][j]
                    + pref[i][j + 1]
                    + pref[i + 1][j]
                    - pref[i][j];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {

            int x = q[0];
            int y = q[1];

            // Check 1 x 1 square first
            if (mat[x][y] > k) {
                ans.push_back(-1);
                continue;
            }

            int maxRadius = min({
                x,
                y,
                n - 1 - x,
                m - 1 - y
            });

            int low = 0;
            int high = maxRadius;
            int best = 0;

            while (low <= high) {

                int radius = low + (high - low) / 2;

                int r1 = x - radius;
                int c1 = y - radius;
                int r2 = x + radius;
                int c2 = y + radius;

                int ones = getSum(pref, r1, c1, r2, c2);

                if (ones <= k) {
                    best = radius;
                    low = radius + 1;
                }
                else {
                    high = radius - 1;
                }
            }

            ans.push_back(2 * best + 1);
        }

        return ans;
    }
};