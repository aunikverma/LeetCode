class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& dir, vector<vector<int>>& mat) {
        for (auto& d : dir) {
            int r = i + d[0], c = j + d[1];
            while (r >= 0 && r < mat.size() && c >= 0 && c < mat[0].size()) {
                if (mat[r][c] == -1 || mat[r][c] == 1) {
                    break;
                }
                if (mat[r][c] == 2) { // already watched cell
                    r += d[0];
                    c += d[1];
                    continue;
                }
                mat[r][c] = 2;
                r += d[0];
                c += d[1];
            }
        }
    }

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> mat(m, vector<int>(n, 0));
        for (auto& e : walls) {
            mat[e[0]][e[1]] = -1;
        }
        for (auto& e : guards) {
            mat[e[0]][e[1]] = 1;
        }
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (auto& v : guards) {
            dfs(v[0], v[1], dir, mat);
        }
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};