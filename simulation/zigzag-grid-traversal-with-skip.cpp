class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> ans;
        int cols = grid[0].size();
        for (int i = 0; i < grid.size(); i++) {
            if (i % 2 == 1) {        // when row is odd
                if (cols % 2 == 0) { // cols size is even then from last index
                    for (int j = grid[0].size() - 1; j >= 0; j -= 2) {
                        ans.push_back(grid[i][j]);
                    }
                } else { // cols size if odd then from second last
                    for (int j = grid[0].size() - 2; j >= 0; j -= 2) {
                        ans.push_back(grid[i][j]);
                    }
                }
            } else { // in even row it always starts from 1
                for (int j = 0; j < grid[0].size(); j += 2) {
                    ans.push_back(grid[i][j]);
                }
            }
        }
        return ans;
    }
};