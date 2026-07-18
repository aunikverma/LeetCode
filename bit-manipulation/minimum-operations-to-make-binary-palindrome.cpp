class Solution {
private:
    bool is_palindrome(const string &s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    string bin(int n) {
        string s;
        while (n > 0) {
            s.push_back((n & 1) + '0');
            n >>= 1;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    vector<int> palindromes;

    void precompute() {
        for (int i = 1; i <= 5000; i++) {
            string s = bin(i);
            if (is_palindrome(s)) {
                palindromes.push_back(i);
            }
        }
    }

    int closestPalindrome(int n) {
        auto it = lower_bound(palindromes.begin(), palindromes.end(), n);
        int ans = INT_MAX;
        if (it != palindromes.end()) ans = min(ans, abs(*it - n));
        if (it != palindromes.begin()) ans = min(ans, abs(*(prev(it)) - n));
        return ans;
    }

public:
    vector<int> minOperations(vector<int>& nums) {
        precompute();
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            string s = bin(nums[i]);
            if (is_palindrome(s)) {
                ans[i] = 0;
            } else {
                ans[i] = closestPalindrome(nums[i]);
            }
        }
        return ans;
    }
};