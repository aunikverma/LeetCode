class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        vector<pair<int, char>> arr;
        for (auto& v : mp) {
            arr.push_back({v.second, v.first});
        }
        sort(arr.begin(), arr.end());
        if (arr.size() <= k) {
            return 0;
        }
        int ans = 0;
        int n = arr.size();
        int i = 0;
        while (n != k) {
            n--;
            ans += arr[i].first;
            i++;
        }
        return ans;
    }
};