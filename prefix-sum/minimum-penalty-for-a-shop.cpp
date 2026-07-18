class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> prefix(n + 1, 0); // N's
        vector<int> suffix(n + 1, 0); // Y's
        for (int i = 0; i < n; i++) {
            if (customers[i] == 'N') {
                prefix[i + 1] = prefix[i] + 1;
            } else {
                prefix[i + 1] = prefix[i];
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (customers[i] == 'Y') {
                suffix[i] = suffix[i + 1] + 1;
            } else {
                suffix[i] = suffix[i + 1];
            }
        }
        int ans = -1, penalty = INT_MAX;
        for (int i = 0; i <= n; i++) {
            if (prefix[i] + suffix[i] < penalty) {
                penalty = prefix[i] + suffix[i];
                ans = i;
            }
        }
        return ans;
    }
};