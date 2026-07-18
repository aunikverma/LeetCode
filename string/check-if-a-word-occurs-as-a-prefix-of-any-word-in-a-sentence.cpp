class Solution {
public:
    int isPrefixOfWord(string s, string sw) {
        int wordIndex = 0;
        int i = 0;
        while (i < s.size()) {
            wordIndex++; // Increment word
            // Check if the current word starts with the prefix
            if (s.substr(i,sw.size()) == sw) {//check if word is starting with the prefix
                return wordIndex;
            }
            // Move to the next word (skip characters until a space is found)
            while (i < s.size() && s[i] != ' ') {
                i++;
            }
            // Skip the space itself
            i++;
        }
        return -1; // Return -1 if no word starts with the prefix
    }
};
