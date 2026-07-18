class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        unordered_map<int, vector<string>> mp; // no of set bits : time string
        for (int h = 0; h <= 11; h++) {
            for (int m = 0; m <= 59; m++) {
                int bits = __builtin_popcount(h) + __builtin_popcount(m);
                string hour = "", min = "";
                if (m < 10) {
                    min += '0';
                }
                min += to_string(m);
                hour += to_string(h);
                mp[bits].push_back(hour + ':' + min);
            }
        }
        vector<string> ans = mp[turnedOn];
        return ans;
    }
};