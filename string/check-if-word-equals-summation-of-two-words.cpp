class Solution {
private:
    int wordtonumber(string s) {
        string a = "";
        for (char c : s) {
            a += to_string(c - 'a'); // converting into string as integer
        }
        return stoi(a);
    }

public:
    bool isSumEqual(string first, string second, string target) {
        int a = wordtonumber(first);
        int b = wordtonumber(second);
        int t = wordtonumber(target);
        return (a + b == t);
    }
};