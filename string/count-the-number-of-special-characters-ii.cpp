class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> indexes(52, -1);
        for (int i = 0; i < word.length(); i++) {
            if (islower(word[i])) {
                // last index of lower case
                indexes[word[i] - 'a'] = i;
            } else {
                // first index of uppercase
                if (indexes[word[i] - 'A' + 26] == -1) {
                    indexes[word[i] - 'A' + 26] = i;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < 26; i++) {
            // if both appear
            if (indexes[i] != -1 && indexes[i + 26] != -1) {
                // if all lower appears first before upper
                if (indexes[i + 26] > indexes[i]) {
                    count++;
                }
            }
        }
        return count;
    }
};