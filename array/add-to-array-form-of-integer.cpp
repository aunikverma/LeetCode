class Solution {
public:
    vector<int> addToArrayForm(vector<int>& n, int k) {
        vector<int> ans;
        int c = 0;
        int i = n.size() - 1;
        while (i >= 0 || k > 0 || c > 0) {
            int d = (i >= 0 ? n[i] : 0); // Get digit from n if valid
            int sum = d + (k % 10) + c; // Add current digit, k's last digit, and carry
            ans.push_back(sum % 10); // Store the last digit of the sum
            c = sum / 10;            // Update carry
            k /= 10;                 // Move to the next digit of k
            i--;                     // Move to the next digit of n
        }
        // Reverse the result as we processed digits from least to most significant
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
