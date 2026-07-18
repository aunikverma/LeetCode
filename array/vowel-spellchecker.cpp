class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist,vector<string>& queries) {
        
        unordered_set<string> exactWords(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelInsensitive;

        auto devowel = [](string word) {
            for (char& c : word) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                    c = '*';
            }
            return word;
        };

        // Preprocess wordlist
        for (string word : wordlist) {
            string lower = word;
            for (char& c : lower)
                c = tolower(c);

            if (!caseInsensitive.count(lower))
                caseInsensitive[lower] = word;

            string v = devowel(lower);
            if (!vowelInsensitive.count(v))
                vowelInsensitive[v] = word;
        }

        vector<string> ans;
        for (string query : queries) {
            if (exactWords.count(query)) {
                ans.push_back(query); // Rule 1: exact match
                continue;
            }

            string lower = query;
            for (char& c : lower)
                c = tolower(c);

            if (caseInsensitive.count(lower)) {
                ans.push_back(
                    caseInsensitive[lower]); // Rule 2: case-insensitive
                continue;
            }

            string v = devowel(lower);
            if (vowelInsensitive.count(v)) {
                ans.push_back(vowelInsensitive[v]); // Rule 3: vowel-insensitive
                continue;
            }

            ans.push_back(""); // Rule 4: no match
        }
        return ans;
    }
};