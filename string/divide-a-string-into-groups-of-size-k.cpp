class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        string a = "";
        for (char c : s) {
            if (a.length() == k) {
                ans.push_back(a); // when length equals k add into the vector
                a = "";
            }
            a += c;
        }
        if (a.length() != 0) { // add fill character till a.length() == k
            while (a.length() < k) {
                a += fill;
            }
            ans.push_back(a);
        }
        return ans;
    }
};