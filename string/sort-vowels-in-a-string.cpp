class Solution {
private:
    bool check(char c) {
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }

public:
    string sortVowels(string s) {
        vector<char> v;
        for (char c : s) {
            if (check(c)) {
                v.push_back(c);
            }
        }
        sort(v.begin(), v.end());
        int count = 0;
        string ans = "";
        for (char c : s) {
            if (check(c)) {
                ans += v[count++];
            } else {
                ans += c;
            }
        }
        return ans;
    }
};