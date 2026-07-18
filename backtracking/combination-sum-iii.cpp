class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    int K;
    void solve(int i, int target) {
        // base case
        if (target == 0 && path.size() == K) {
            ans.push_back(path);
            return;
        }
        for (int j = i; j <= 9; j++) {
            if (path.size() >= K) {
                continue;
            }
            if (target - j < 0) {
                break;
            }
            path.push_back(j);
            solve(j + 1, target - j);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        K = k;
        solve(1, n);
        return ans;
    }
};