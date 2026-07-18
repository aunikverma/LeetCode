class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }
        int maxf = INT_MIN; //max frequency
        for (auto& v : mp) {
            if (v.second >= maxf) {
                maxf = v.second;
            }
        }
        int sum = 0;
        for (auto& v : mp) { //sum of all frequency having max frequency
            if (v.second == maxf) {
                sum += v.second;
            }
        }
        return sum;
    }
};