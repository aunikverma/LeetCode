class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int, int> mp;
        for (int i : banned) {
            mp[i] = 1;
        }
        int sum = 0;
        int c = 0;
        for (int i = 1; i <= n; i++) {
            if (mp.find(i) != mp.end()) {
                continue;
            } else {
                sum += i;
                if (sum <= maxSum) {
                    c++;
                } else {
                    break;
                }
            }
        }
        return c;
    }
};