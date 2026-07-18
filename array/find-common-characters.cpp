class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<char> count(26, 0);
        for (char c : words[0]) { //freq of first words
            count[c - 'a']++;
        }
        for (int i = 1; i < words.size(); i++) {
            vector<char> count1(26, 0);
            for (char c : words[i]) { //freq map of second word
                count1[c - 'a']++;
            }
            for (int j = 0; j < 26; j++) { //update count on account of count 1 min freq
                count[j] = min(count[j], count1[j]);
            }
        }
        vector<string> ans;
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) { //add char no of count[i] times
                char c = 'a' + i;
                for (int j = 0; j < count[i]; j++) {
                    string a = "";
                    a += c;
                    ans.push_back(a);
                }
            }
        }
        return ans;
    }
};