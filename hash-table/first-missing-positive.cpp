class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        for (int i : nums) {
            if (i > 0) {
                s.insert(i);
            }
        }
        for (int i = 1; i <= nums.size() + 1; i++) {
            if (s.find(i) == s.end()) {
                return i;
            }
        }
        return -1;
    }
};