class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int i : digits) {
            freq[i] += 1;
        }
        int count = 0;
        for (int i = 100; i <= 999; i++) {
            if (i & 1) {
                continue;
            }
            unordered_map<int, int> mp;
            int n = i;
            while (n > 0) {
                mp[n % 10] += 1;
                n /= 10;
            }
            bool present = true;
            for (auto& v : mp) {
                if (freq[v.first] < v.second) {
                    present = false;
                }
            }
            if (present) {
                count += 1;
            }
        }
        return count;
    }
};