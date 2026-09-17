class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n, INT_MAX);

        int curr_sum = 0, best_min = INT_MAX;
        int l = 0;

        int ans = INT_MAX;
        for (int r = 0; r < n; r++) {
            curr_sum += arr[r];
            // shrink
            while (curr_sum > target) {
                curr_sum -= arr[l];
                l++;
            }
            if (curr_sum == target) {
                if (r - 1 >= 0 && min_len[r - 1] != INT_MAX) {
                    ans = min(ans, (r - l + 1) + min_len[r - 1]);
                }
                best_min = min(best_min, r - l + 1);
            }

            min_len[r] = best_min;
        }
        return (ans != INT_MAX ? ans : -1);
    }
};