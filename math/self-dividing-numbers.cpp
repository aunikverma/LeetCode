class Solution {
private:
    bool check(int n) {
        int a = n;
        while (a > 0) {
            int r = a % 10;
            if (r == 0 || n % r != 0) {
                return false;
            }
            a /= 10;
        }
        return true;
    }

public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            if (check(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};