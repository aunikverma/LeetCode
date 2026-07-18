class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // least size
        int ans = 1;
        // freq map
        unordered_map<long long, int> mp;
        for (int i : nums) {
            mp[i] += 1;
        }

        // collect odd ones if any
        if (mp.count(1)) {
            int freq = (mp[1] & 1 ? mp[1] : mp[1] - 1);
            ans = max(ans, freq);
        }

        // try to make subset with every no
        for (auto& v : mp) {
            if (v.first != 1) {
                int count = 0;
                long long curr = v.first;
                // since we want odd no of elements
                while (mp.count(curr) && mp[curr] > 1) {
                    curr = pow(curr, 2);
                    if (mp.count(curr)) {
                        count += 2;
                    } else {
                        count += 1;
                    }
                }
                // if last curr was present one time
                if (mp.count(curr)) {
                    count += 1;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};
// since either we choose odd no of ones
// try until we found sqaures