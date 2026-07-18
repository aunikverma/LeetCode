// // Optimized Approach - O(n^2 logn + nlogn) - o(n^2 logn) time and O(n) space
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int target = 0;                 // target is 0
//         sort(nums.begin(), nums.end()); // sorted the numbers
//         set<vector<int>> s;             // vector set
//         vector<vector<int>> output;     // output vector triplet
//         for (int i = 0; i < nums.size(); i++) {
//             if (i > 0 && nums[i] == nums[i - 1]) continue;//for excluding
//             repeated values int j = i + 1; int k = nums.size() - 1; while (j
//             < k) {
//                 int sum = nums[i] + nums[j] + nums[k];
//                 if (sum == target) {
//                     s.insert({nums[i], nums[j], nums[k]});
//                     j++;
//                     k--;
// while (j < k && nums[j] == nums[j - 1])//after j
//                       j++;
//                 } else if (sum < target) {
//                     j++;
//                 } else {
//                     k--;
//                 }
//             }
//         }
//         for (auto triplets : s)
//             output.push_back(triplets);
//         return output;
//     }
// };

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int t = nums[i] + nums[j] + nums[k];
                if (t > 0)
                    k--;
                else if (t < 0)
                    j++;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) // after j
                        j++;
                    while (j < k && nums[k] == nums[k + 1]) // before k
                        k--;
                }
            }
        }
        return ans;
    }
};