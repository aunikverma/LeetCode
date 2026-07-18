class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        vector<int> prefix;
        vector<int> suffix(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) { // preifx sum
            if (i == 0) {
                prefix.push_back(nums[i]);
            } else {
                prefix.push_back(nums[i] + prefix[i - 1]);
            }
        }
        for (int i = nums.size() - 1; i >= 0; i--) { // suffix sum
            if (i == nums.size() - 1) {
                suffix[i] = nums[i];
            } else {
                suffix[i] = nums[i] + suffix[i + 1];
            }
        }
        // now check
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                int leftsum = (i > 0) ? prefix[i - 1] : 0;
                int rightsum = (i < nums.size() - 1) ? suffix[i + 1] : 0;
                if (leftsum == rightsum) {
                    ans += 2;
                } else if (abs(leftsum - rightsum) == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};