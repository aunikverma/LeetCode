class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = accumulate(arr.begin(), arr.end(), 0);
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            arr[i] += arr[i - 1];
        }
        int k = 2;
        while (k < n) {
            for (int i = 0; i + k < n; i++) {
                if (i == 0) {
                    ans += arr[i + k];
                } else {
                    ans += (arr[i + k] - arr[i - 1]);
                }
            }
            k += 2;
        }
        return ans;
    }
};