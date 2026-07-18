class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> ans;
        while (n > 0) {
            ans.push_back(n % 10);
            n /= 10;
        }
        reverse(ans.begin(), ans.end()); // msb to lsb
        int c = 1, sum = 0;
        for (int i : ans) {
            sum += i*c;
            c *= -1;
        }
        return sum;
    }
};