class Solution {
public:
    int n, m;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int i, int j, vector<vector<int>>& mat,
             vector<vector<bool>>& vis) {

        vis[i][j] = true;

        for(auto &d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];

            if(ni >= 0 && ni < n && nj >= 0 && nj < m &&
               !vis[ni][nj] &&
               mat[ni][nj] >= mat[i][j]) {

                dfs(ni, nj, mat, vis);
            }
        }
    }

    int countCoordinates(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();

        vector<vector<bool>> p(n, vector<bool>(m, false));
        vector<vector<bool>> q(n, vector<bool>(m, false));

        for(int j = 0; j < m; j++)
            if(!p[0][j]) dfs(0, j, mat, p);

        for(int i = 0; i < n; i++)
            if(!p[i][0]) dfs(i, 0, mat, p);

        for(int j = 0; j < m; j++)
            if(!q[n-1][j]) dfs(n-1, j, mat, q);

        for(int i = 0; i < n; i++)
            if(!q[i][m-1]) dfs(i, m-1, mat, q);

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(p[i][j] && q[i][j])
                    ans++;
            }
        }

        return ans;
    }
};