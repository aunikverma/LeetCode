class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int> st;
        // ref used so st and sum can be accessed
        auto addSet = [&](int sum) {
            st.insert(sum);
            if (st.size() > 3) {
                st.erase(st.begin());
            }
        };

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                // 0 side rhombus
                addSet(grid[r][c]);
                // other sides
                for (int side = 1; r - side >= 0 && r + side < m &&
                                   c - side >= 0 && c + side < n;
                     side++) {
                    int sum = 0;
                    for (int k = 0; k <= side - 1; k++) {
                        sum += grid[r - side + k][c + k];
                        sum += grid[r + k][c + side - k];
                        sum += grid[r + side - k][c - k]; // bottom vertex to left vertex
                        sum += grid[r - k][c - side + k]; // left verter to top vertex
                    }
                    addSet(sum);
                }
            }
        }
        vector<int> ans(st.rbegin(), st.rend());
        return ans;
    }
};