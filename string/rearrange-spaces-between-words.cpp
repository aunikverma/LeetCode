class Solution {
public:
    string reorderSpaces(string text) {
        string w = "";
        vector<string> word;
        int count = 0;
        for (char c : text) {
            if (c == ' ') {
                count++;
            } else if (c != ' ') {
                w += c;
            }
            if (c == ' ' && !w.empty()) {
                word.push_back(w); // adding words into vector word
                w = "";
            }
        }
        if (!w.empty()) {
            word.push_back(w); // adding last words if it's there
        }
        int d = (word.size() == 1) ? d = count : d = count / (word.size() - 1); // counting even spaces
        string ans = "";
        for (auto& i : word) { // adding ans
            ans += i;
            for (int i = 0; i < d; i++) {
                ans += ' ';
            }
            count -= d;
        }
        if (count < 0) {
            ans = ans.substr(0, text.length()); // removing extra space
        } else {
            for (int i = 0; i < count; i++) { // if remaining spaces
                ans += ' ';
            }
        }
        return ans;
    }
};