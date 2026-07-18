class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int l = log10(low) + 1;
        int r = log10(high) + 1;
        string s = "123456789";
        vector<int> ans;
        for (int len = l; len <= r; len++) {
            for (int i = 0; i <= (9 - len); i++) {
                string s1 = s.substr(i, len);
                int a = stoi(s1);
                if (a >= low && a <= high) {
                    ans.push_back(a);
                }
            }
        }
        return ans;
    }
};