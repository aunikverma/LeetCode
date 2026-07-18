class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            set<int> even;
            set<int> odd;
            if (nums[i] & 1) {
                odd.insert(nums[i]);
            } else {
                even.insert(nums[i]);
            }
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] & 1) {
                    odd.insert(nums[j]);
                } else {
                    even.insert(nums[j]);
                }
                if (odd.size() == even.size()) {
                    ans = max(ans, j - i + 1);
                }
            }
            if (ans == nums.size() - 1) {
                break;
            }
        }
        return ans;
    }
};
//finding each subarray and checking the condition
//of balanced subarray