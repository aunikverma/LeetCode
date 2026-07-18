class Solution {
public:
    string largestGoodInteger(string num) {
        vector<string> a;
        string ans = "";
        for (int i = 9; i >= 0; i--) {
            if (i == 0) {
                a.push_back("000");
            } else {
                a.push_back(to_string(i * 111));
            }
        }
        for (auto i : a) {
            if (num.find(i) < num.length()) {
                return i;
            }
        }
        return ans;
    }
};