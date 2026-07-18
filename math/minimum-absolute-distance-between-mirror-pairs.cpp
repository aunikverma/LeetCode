class Solution {
public:
    int rev(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        int i = 0;
        while (i < s.length() && s[i] == '0') {
            i++;
        }
        s = s.substr(i);
        int ans = stoi(s);
        return ans;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            // if not add reverse and index
            if (mp.find(nums[i]) == mp.end()) {
                mp[rev(nums[i])] = i;
            } else {
                // if present update ans and push its reverse with index
                ans = min(ans, abs(mp[nums[i]] - i));
                mp[rev(nums[i])] = i;
            }
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};