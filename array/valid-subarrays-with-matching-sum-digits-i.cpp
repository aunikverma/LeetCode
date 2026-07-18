class Solution {
public:
    bool check(long long n, int x) {
        int last = n % 10;
        int first;
        while (n >= 10) {
            n /= 10;
        }
        first = n;
        return (first == x && last == x);
    }

    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            long long sum = nums[i];
            if (check(sum, x)) {
                count += 1;
            }
            for (int j = i + 1; j < n; j++) {
                sum += nums[j];
                if (check(sum, x)) {
                    count += 1;
                }
            }
        }
        return count;
    }
};