class Solution {
public:
    bool is_vowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    string toGoatLatin(string sentence) {
        vector<string> arr;
        stringstream ss(sentence);
        string token;
        while (getline(ss, token, ' ')) {
            arr.push_back(token);
        }
        sentence = "";
        string count = "a";
        for (auto& i : arr) {
            string w = i; // word
            if (is_vowel(w[0])) {
                w += "ma" + count;
                count += 'a';
            } else {
                w.push_back(w[0]);
                w = w.substr(1);
                w += "ma" + count;
                count += 'a';
            }
            sentence += w + " ";
        }
        return sentence.substr(0, sentence.length() - 1);
    }
};