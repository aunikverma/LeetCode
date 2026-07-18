class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        string n1 = "", n2 = "";
        for (int i = 0; i < s.length(); i += 2) {
            n1 += s[i];
        }
        for (int i = 1; i < s.length(); i += 2) {
            n2 += s[i];
        }
        int ans = stoi(n1) + stoi(n2);
        return ans;
    }
};