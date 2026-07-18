class Solution {
public:
    int n;
    void solve(int i, vector<int>& candidates, int target, vector<int>& path, set<vector<int>>& ans) {
        // found
        if (target == 0) {
            ans.insert(path);
            return;
        }
        // base case
        if (target < 0 || i >= n) {
            return;
        }
        // include
        path.push_back(candidates[i]);
        // take and move
        solve(i + 1, candidates, target - candidates[i], path, ans);
        // or choose multiple time
        solve(i, candidates, target - candidates[i], path, ans);
        // exclude
        path.pop_back();
        // not take and move
        solve(i + 1, candidates, target, path, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        set<vector<int>>ans;
        vector<int> path;
        solve(0, candidates, target, path, ans);
        vector<vector<int>>result(ans.begin(),ans.end());
        return result;
    }
};