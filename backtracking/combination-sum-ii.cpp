class Solution {
public:
    int n;
    vector<vector<int>> ans;
    vector<int> path;

    void solve(int i, int target, vector<int>& candidates) {
        // base case
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        for (int j = i; j < n; j++) {
            if (j > i && candidates[j] == candidates[j - 1]) {
                continue;
            }
            if (target - candidates[j] < 0) {
                break;
            }
            path.push_back(candidates[j]);
            solve(j + 1, target - candidates[j], candidates);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        // sort candidates
        sort(candidates.begin(), candidates.end());
        solve(0, target, candidates);
        return ans;
    }
};