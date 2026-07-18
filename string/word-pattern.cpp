class Solution {
public:
    bool wordPattern(string p, string s) {
        vector<string> a;
        string s1 = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                a.push_back(s1);
                s1 = "";
            } else {
                s1 += s[i];
            }
        }
        a.push_back(s1); // last word because doesn't encounter with space ' '
        if (a.size() != p.size()) {
            return false;
        }
        unordered_map<char, int> mp;
        unordered_map<string, int> mp1;
        for (int i = 0; i < a.size(); i++) {
            if (mp.find(p[i]) == mp.end()) {
                mp[p[i]] = i;
            }
            if (mp1.find(a[i]) == mp1.end()) {
                mp1[a[i]] = i;
            }
            if (mp[p[i]] != mp1[a[i]]) {
                return false;
            }
        }
        return true;
    }
};

class Solution1 {
public:
    bool wordPattern(string p, string s) {
        // Split the string `s` into words
        vector<string> a;
        string s1 = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                a.push_back(s1);
                s1 = "";
            } else {
                s1 += s[i];
            }
        }
        a.push_back(s1); // Add the last word to the vector

        // Check if the number of words matches the length of the pattern
        if (a.size() != p.size()) {
            return false;
        }

        // Maps to track character-to-word and word-to-character mappings
        unordered_map<char, int> mp;
        unordered_map<string, int> mp1;

        for (int i = 0; i < a.size(); i++) {
            if (mp.find(p[i]) == mp.end()) {
                mp[p[i]] = i;
            }
            if (mp1.find(a[i]) == mp1.end()) {
                mp1[a[i]] = i;
            }
            // If mappings do not match, return false
            if (mp[p[i]] != mp1[a[i]]) {
                return false;
            }
        }
        return true;
    }
};
