class Solution {
private:
    void getall(string s, string ans, int st, vector<string>& allcom,string map[]) {
        // base case
        if (st == s.length()) {
            allcom.push_back(ans);
            return;
        }

        int number = s[st] - '0';   // digits[st]
        string value = map[number]; // value
        // inclusion
        for (int i = 0; i < value.length(); i++) {
            ans.push_back(value[i]);
            getall(s, ans, st + 1, allcom, map);
            ans.pop_back(); // backtrack value[i]
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> allcom;
        string ans;
         if(digits.length() == 0) return allcom;
        string map[10] = {"","","abc",  "def", "ghi","jkl", "mno", "pqrs", "tuv", "wxyz"};
        getall(digits, ans, 0, allcom,map);
        return allcom;
    }
};