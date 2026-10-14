class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        int digit_sum = sum;
        int ans_sum = 0;
        for (int i = 0; i < num; i++) {
            if (sum > 9) {
                ans += '9';
                ans_sum += 9;
                sum -= 9;
            } else {
                if (sum == 0) {
                    ans += '0';
                } else {
                    ans += '0' + (sum - 0);
                    ans_sum += sum;
                    sum = 0;
                }
            }
        }
        return (ans_sum == digit_sum ? ans : "");
    }
};