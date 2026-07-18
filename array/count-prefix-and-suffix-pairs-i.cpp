class Solution {
private:
    bool check(string s1, string s2) {
        if (s2.length() < s1.length())
            return false;
        string a = s2.substr(0, s1.length());
        string b = s2.substr(s2.length() - s1.length());
        return (s1 == a && s1 == b);
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (check(words[i], words[j])) {
                    ans++;
                }
            }
        }
        return ans;
    }
};