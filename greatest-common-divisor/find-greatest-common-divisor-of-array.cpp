class Solution {
public:
    int findGCD(vector<int>& nums) {
        auto maxi = max_element(nums.begin(), nums.end());
        auto mini = min_element(nums.begin(), nums.end());
        return __gcd(*maxi, *mini);
    }
};