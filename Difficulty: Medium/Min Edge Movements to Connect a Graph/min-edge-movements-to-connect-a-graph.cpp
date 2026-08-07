class Solution {
public:
    vector<int> parent, rankv;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (rankv[a] < rankv[b])
            swap(a, b);

        parent[b] = a;

        if (rankv[a] == rankv[b])
            rankv[a]++;
    }

    int minEdgesReq(int n, vector<vector<int>>& edges) {
        int m = edges.size();

        // Not enough edges to make the graph connected
        if (m < n - 1)
            return -1;

        parent.resize(n);
        rankv.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int components = n;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (find(u) != find(v)) {
                unite(u, v);
                components--;
            }
        }

        return components - 1;
    }
};