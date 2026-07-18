class Solution {
public:
    int m, n;
    bool isSafe(int r, int c, int& st, vector<vector<int>>& image,
                vector<vector<bool>>& visited) {
        if (r >= 0 && r < m && c >= 0 && c < n && image[r][c] == st &&
            !visited[r][c]) {
            return true;
        }
        return false;
    }
    void dfs(int r, int c, vector<vector<int>>& image,
             vector<vector<bool>>& visited, int& color, int& st,
             vector<vector<int>>& dir) {
        image[r][c] = color;
        visited[r][c] = true;
        for (auto& d : dir) {
            int new_r = r + d[0], new_c = c + d[1];
            while (isSafe(new_r, new_c, st, image, visited)) {
                dfs(new_r, new_c, image, visited, color, st, dir);
                new_r += d[0];
                new_c = d[1];
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        m = image.size();
        n = image[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int st = image[sr][sc];
        dfs(sr, sc, image, visited, color, st, dir);
        return image;
    }
};