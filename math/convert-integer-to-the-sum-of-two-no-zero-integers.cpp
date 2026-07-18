class Solution {
private:
    bool check(int n) {
        while (n > 0) {
            if (n % 10 == 0)
                return false; // last digit
            n /= 10;
        }
        return true;
    }

public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            int j = n - i;
            if (check(i) && check(j)) {
                return {i, j};
            }
        }
        return {};
    }
};