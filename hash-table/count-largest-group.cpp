class Solution {
private:
    int digit_sum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int countLargestGroup(int n) {
        vector<int> arr(37, 0);
        for (int i = 1; i <= n; i++) {
            int a = digit_sum(i);
            arr[a] += 1;
        }
        int max_size = INT_MIN;
        for (int i = 0; i < 37; i++) {
            max_size = max(max_size, arr[i]);
        }
        int count = 0;
        for (int i = 0; i < 37; i++) {
            if (arr[i] == max_size) {
                count++;
            }
        }
        return count;
    }
};