class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> s = {".-",   "-...", "-.-.", "-..",  ".",    "..-.",
                            "--.",  "....", "..",   ".---", "-.-",  ".-..",
                            "--",   "-.",   "---",  ".--.", "--.-", ".-.",
                            "...",  "-",    "..-",  "...-", ".--",  "-..-",
                            "-.--", "--.."};
        set<string> s1;
        for (auto& v : words) {
            string a = "";
            for (char c : v) {
                a += s[c - 'a'];
            }
            s1.insert(a);
        }
        return s1.size();
    }
};