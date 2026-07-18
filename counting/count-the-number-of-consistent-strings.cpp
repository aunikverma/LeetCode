class Solution {
public:
    int countConsistentStrings(string arr, vector<string>& w) {
        int a = 0;
        set<int> s;
        for (char c : arr) {
            s.insert(c - 'a');
        }
        for (auto& v : w) {
            for (char c : v) {
                if (s.find(c - 'a') == s.end()) {
                    a++;
                    break;
                }
            }
        }
        return (w.size() - a);
    }
};