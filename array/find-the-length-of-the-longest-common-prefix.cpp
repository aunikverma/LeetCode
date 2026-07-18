class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        for (int i : arr1) {
            if (!mp.count(i)) {
                string s = to_string(i);
                int n = 0;
                for (int i = 0; i < s.length(); i++) {
                    n = n * 10 + (s[i] - '0');
                    mp[n] = i + 1;
                }
            }
        }
        int ans = INT_MIN;
        for (int i : arr2) {
            string s = to_string(i);
            int n = 0;
            for (char c : s) {
                n = n * 10 + (c - '0');
                if (mp.count(n)) {
                    ans = max(ans, mp[n]);
                }
            }
        }
        return (ans == INT_MIN ? 0 : ans);
    }
};