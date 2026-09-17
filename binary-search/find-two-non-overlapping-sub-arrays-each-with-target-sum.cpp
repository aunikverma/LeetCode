class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n, INT_MAX);
        int ans = INT_MAX;
        int l = 0, curr_sum = 0;
        int curr_minlen = INT_MAX;

        for (int r = 0; r < n; r++) {
            curr_sum += arr[r];
            // shrink
            while (l < r && curr_sum > target) {
                curr_sum -= arr[l++];
            }
            if (curr_sum == target) {
                int len = r - l + 1;
                // min before this win[l..r]
                if (l > 0 && min_len[l - 1] != INT_MAX) {
                    ans = min(ans, len + min_len[l - 1]);
                    curr_minlen = min(curr_minlen, len);
                }
                curr_minlen = min(curr_minlen, len);
            }
            min_len[r] = curr_minlen;
        }
        return (ans != INT_MAX ? ans : -1);
    }
};