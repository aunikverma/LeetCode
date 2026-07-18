class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            int mod = (num % value + value) % value;
            freq[mod]++;
        }

        int x = 0;
        while (true) {
            int mod = x % value;
            if (freq[mod] > 0) {
                freq[mod]--;
                x++;
            } else {
                return x;
            }
        }
    }
};

// We’re trying to find the smallest non-negative integer that cannot be formed
// by adding or subtracting value any number of times to elements in nums.

// The trick is:

// Every number x can be formed only if we have enough numbers in nums that
// match x % value.

// So we simulate forming x = 0, 1, 2, ... and check if we have enough of each
// remainder.