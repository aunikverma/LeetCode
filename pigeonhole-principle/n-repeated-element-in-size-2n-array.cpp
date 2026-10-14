class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans;
        for (int i : nums) {
            if (mp.find(i) == mp.end()) {
                mp[i]++;
            } else if (mp[i] == 1) { //only 1 element is repeating
                ans = i;
                break;
            }
        }
        return ans;
    }
};