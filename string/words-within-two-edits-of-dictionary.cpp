class Solution {
public:
    bool check(string& a, string& b) {
        int diff = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) {
                diff++;
            }
            if (diff > 2) {
                return false;
            }
        }
        return true;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for (int i = 0; i < queries.size(); i++) {
            for (int j = 0; j < dictionary.size(); j++) {
                if (check(queries[i], dictionary[j])) {
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};