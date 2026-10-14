class Solution {
private:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count_ones = (nums[0] == 1) ? 1 : 0;
        int all_gcd = nums[0];
        for (int i = 1; i < n; ++i) {
            all_gcd = gcd(all_gcd, nums[i]);
            if (nums[i] == 1) {
                count_ones++;
            }
        }
        if (count_ones > 0) {
            return (n - count_ones);
        }
        if (all_gcd != 1) { //if not any with gcd 1
            return -1;
        }
        int minLen = n; //length of shortest subarray
        for (int i = 0; i < n; ++i) {
            int curr = nums[i];
            for (int j = i + 1; j < n; ++j) {
                curr = gcd(curr, nums[j]);
                if (curr == 1) {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }
        return minLen - 1 + (n - 1); //operations min - 1 + length - 1
    }
};