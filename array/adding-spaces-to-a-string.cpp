class Solution {
public:
    string addSpaces(string s, vector<int>& sp) {
        string a = "";
        int st = 0;
        for (int i : sp) {
            a += s.substr(st, i - st) + " ";
            st = i;
        }
        a += s.substr(st);
        return a;
    }
};