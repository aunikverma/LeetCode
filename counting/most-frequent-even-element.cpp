class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> mp;
        int ans = -1;
        int count = 0;
        for (int i : nums) {
            if (i % 2 == 0) {
                mp[i]++;
            }
        }
        for (auto& v : mp) {
            if (v.second > count) {
                ans = v.first;
                count = v.second;
            }
        }
        return ans;
    }
};