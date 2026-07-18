class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int i : nums) {
            string a = to_string(i);
            for (char c : a) {
                ans.push_back(c - '0');
            }
        }
        return ans;
    }
};