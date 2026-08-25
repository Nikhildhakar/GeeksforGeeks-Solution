class Solution {
public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        vector<long long> dist(V, 0);

        for (int i = 0; i < V - 1; i++) {
            bool changed = false;

            for (auto &e : edges) {
                int u = e[0];
                int v = e[1];
                int w = e[2];

                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    changed = true;
                }
            }

            if (!changed)
                break;
        }

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if (dist[v] > dist[u] + w)
                return true;
        }

        return false;
    }
};