class Fenwick {
public:
    vector<int> bit;
    int n;

    Fenwick(int size) {
        n = size;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
};

class Solution {
public:
    long long countSubstring(string s) {
        int n = s.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '1')
                prefix[i] = prefix[i - 1] + 1;
            else
                prefix[i] = prefix[i - 1] - 1;
        }

        vector<int> comp = prefix;
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());

        Fenwick ft(comp.size());

        long long ans = 0;

        for (int x : prefix) {
            int idx = lower_bound(comp.begin(), comp.end(), x) - comp.begin() + 1;

            ans += ft.query(idx - 1);

            ft.update(idx, 1);
        }

        return ans;
    }
};