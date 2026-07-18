class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token = "";
        vector<string> words;
        //removing all spaces
        while (ss >> token) {
            words.push_back(token);
        }
        reverse(words.begin(), words.end());
        string ans = "";
        for (int i = 0; i < words.size(); i++) {
            if (i == words.size() - 1) {
                ans += words[i];
                break;
            }
            ans += words[i] + ' ';
        }
        return ans;
    }
};