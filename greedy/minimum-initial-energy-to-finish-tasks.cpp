class Solution {
public:
    static bool Comp(vector<int>& a, vector<int>& b) { return (a[2] > b[2]); }

    bool isPossible(vector<vector<int>>& tasks, int k) {
        for (auto& i : tasks) {
            if (k >= i[1]) {
                k -= i[0];
            } else {
                return false;
            }
        }
        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        for (auto& i : tasks) {
            // remaining
            i.push_back(i[1] - i[0]);
        }
        // doing tasks first which has more remaining value and if same then max
        // min value
        sort(tasks.begin(), tasks.end(), Comp);
        int l = 1, r = 1e9;
        int ans = INT_MAX;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isPossible(tasks, mid)) {
                ans = min(ans, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};