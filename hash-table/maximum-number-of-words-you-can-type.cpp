class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> broken(26, 0);
        for (char c : brokenLetters)
            broken[c - 'a']++;
        stringstream ss(text);
        string token;
        vector<string> v; // string split(' ')
        while (getline(ss, token, ' ')) {
            v.push_back(token);
        }
        int ans = 0;
        for (auto i : v) {
            bool v = true;
            for (char c : i) {
                if (broken[c - 'a'] > 0) { // if any key broken
                    v = false;
                    break;
                }
            }
            if (v)
                ans++;
        }
        return ans;
    }
};