class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long m = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    long long a = (long long)(nums[i] - nums[j]) * nums[k];
                    m = max(m, a);
                }
            }
        }
        return max(m, 0LL);
    }
};