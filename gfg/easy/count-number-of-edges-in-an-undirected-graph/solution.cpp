class Solution {
  public:
    int countEdges(vector<vector<int>>& adj) {
        long long totalDegree = 0;
        for (const auto& neighbors : adj) {
            totalDegree += neighbors.size();
        }
        return static_cast<int>(totalDegree / 2);
    }
};