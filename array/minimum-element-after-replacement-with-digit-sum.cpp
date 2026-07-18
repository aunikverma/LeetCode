class Solution {
private:
    int digitsum(int n) {
        int s = 0;
        while (n > 0) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }

public:
    int minElement(vector<int>& nums) {
        int m = INT_MAX;
        for (int i : nums) {
            m = min(m, digitsum(i));
        }
        return m;
    }
};