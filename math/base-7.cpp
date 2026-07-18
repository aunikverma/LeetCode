class Solution {
public:
    string convertToBase7(int n) {
        if (n == 0) return "0"; // Special case for zero
        string ans = "";
        int c = n;
        if (n < 0) n = -n; // Work with positive value for the conversion
        while (n > 0) {
            ans += to_string(n % 7);
            n /= 7;
        }
        // Reverse the result to get the correct order
        reverse(ans.begin(), ans.end());
        // Add negative sign if the number was originally negative
        if (c < 0) {
            ans = "-" + ans;
        }

        return ans;
    }
};
