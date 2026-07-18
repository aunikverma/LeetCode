class Solution {
public:
    int similarPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            set<char> s(words[i].begin(), words[i].end());
            for (int j = i + 1; j < n; j++) {
                set<char> s1(words[j].begin(), words[j].end());
                if (s == s1) count++;
            }
        }
        return count;
    }
};