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
    int countBalls(int lowLimit, int highLimit) {
        vector<int> arr(46, 0);
        for (int i = lowLimit; i <= highLimit; i++) {
            int a = digit_sum(i);
            arr[a] += 1;
        }
        int max_size = INT_MIN;
        for (int i = 0; i < 46; i++) {
            max_size = max(max_size, arr[i]);
        }
        return max_size;
    }
};