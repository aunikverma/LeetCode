class Solution {
public:
    int find_range(int n) {
        int maxi = -1, mini = 10;
        while (n > 0) {
            int r = n % 10;
            maxi = max(maxi, r);
            mini = min(mini, r);
            n /= 10;
        }
        return (maxi - mini);
    }

    int maxDigitRange(vector<int>& nums) {
        int max_range = -1;
        for (int i : nums) {
            max_range = max(max_range, find_range(i));
        }
        int ans = 0;
        for (int i : nums) {
            if (find_range(i) == max_range) {
                ans += i;
            }
        }
        return ans;
    }
};