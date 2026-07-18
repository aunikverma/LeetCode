class Solution {
private:
    bool check(int n) {
        if (n == 1)
            return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            int a = nums[i][i];         // main diagonal
            int b = nums[i][n - i - 1]; // anti diagonal
            if (check(a))
                ans = max(ans, a);
            if (check(b))
                ans = max(ans, b);
        }
        return ans;
    }
};