
class Solution {
public:
    vector<int> maxDistance(int V, int src, vector<vector<int>>& edges) {
        
        // Adjacency list
        vector<vector<pair<int, int>>> adj(V);
        vector<int> indegree(V, 0);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            indegree[v]++;
        }

        // Topological Sort using Kahn's Algorithm
        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            topo.push_back(u);

            for (auto &[v, w] : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        // Initialize distances
        vector<int> dist(V, INT_MIN);
        dist[src] = 0;

        // Relax edges in topological order
        for (int u : topo) {

            // Ignore unreachable vertices
            if (dist[u] == INT_MIN)
                continue;

            for (auto &[v, w] : adj[u]) {
                dist[v] = max(dist[v], dist[u] + w);
            }
        }

        return dist;
    }
};