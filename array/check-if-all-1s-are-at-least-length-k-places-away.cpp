class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int> a;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                a.push_back(i);
            }
        }
        if (a.empty()) {
            return true;
        }
        for (int i = 0; i < a.size() - 1; i++) {
            if (a[i + 1] - a[i] - 1 < k) {
                return false;
            }
        }
        return true;
    }
};