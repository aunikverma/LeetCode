class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> mp; // diagonal -> list of elements
        int row = nums.size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                mp[i + j].push_back(nums[i][j]);
            }
        }
        vector<int> ans;
        for (auto& p : mp) {
            auto& arr = p.second;
            // need to reverse order while collecting
            for (int k = arr.size() - 1; k >= 0; k--) {
                ans.push_back(arr[k]);
            }
        }
        return ans;
    }
};