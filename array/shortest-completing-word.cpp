
class Solution {
public:
    string shortestCompletingWord(string l, vector<string>& words) {
        unordered_map<char, int> license_freq;
        for (char c : l) {
            if (isalpha(c)) {
                license_freq[tolower(c)]++;
            }
        }
        string ans = "";
        for (const string& word : words) {
            unordered_map<char, int> word_freq;
            for (char c : word) {
                word_freq[tolower(c)]++;
            }
            // Check if the word contains at least the same frequency of each
            bool isValid = true;
            for (const auto& pair : license_freq) {
                if (word_freq[pair.first] < pair.second) {
                    isValid = false; // Word doesn't satisfy the condition
                    break;
                }
            }
            if (isValid && (ans.empty() || word.size() < ans.size())) {
                ans = word;
            }
        }
        return ans; // Return the shortest valid word
    }
};
