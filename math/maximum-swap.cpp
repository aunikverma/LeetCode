class Solution {
public:
    int maximumSwap(int num) {
        unordered_map<char, int> mp;
        string s = to_string(num);
        for (int i = 0; i < s.size(); i++) {
            // find the last index of each digit
            mp[s[i]] = i;
        }
        string a = s;
        sort(a.rbegin(), a.rend());
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != a[i]) {
                // find the first mismatch and swap it with the last occurent of
                // the greatest character available
                swap(s[i], s[mp[a[i]]]);
                break;
            }
        }
        return stoi(s);
    }
};