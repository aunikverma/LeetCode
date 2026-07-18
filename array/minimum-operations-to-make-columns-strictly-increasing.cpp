class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        if (grid.size() <= 1)
            return 0; // size less than 1
        int ans = 0;
        for (int i = 0; i < grid[0].size(); i++) {
            int first = grid[0][i]; // storing first column element
            for (int j = 1; j < grid.size(); j++) {
                if (grid[j][i] <= first) { // when small find diff and add to ans
                    int c = first - grid[j][i] + 1;
                    cout << c << "->";
                    ans += c;
                    grid[j][i] += c;
                    first = grid[j][i]; // update first
                } else {
                    first = max(first, grid[j][i]); // update first
                }
            }
        }
        return ans;
    }
};