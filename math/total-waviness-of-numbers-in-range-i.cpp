class Solution {
public:
    int waiveness(int n) {
        if (n <= 100) {
            return 0;
        }
        int count = 0;
        string s = to_string(n);
        for (int i = 1; i <= s.length() - 2; i++) {
            int prev = s[i - 1] - '0', curr = s[i] - '0', next = s[i + 1] - '0';
            // peak
            if (curr > prev && curr > next) {
                count += 1;
            }
            // valley
            else if (curr < prev && curr < next) {
                count += 1;
            }
        }
        return count;
    }

    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for (int i = num1; i <= num2; i++) {
            ans += waiveness(i);
        }
        return ans;
    }
};