class Solution {
public:
    string solve(string s) {
        vector<string> specials;
        int start = 0, sum = 0;
        for (int i = 0; i < s.length(); i++) {
            sum += (s[i] == '1' ? 1 : -1);
            if (sum == 0) {
                string inner = s.substr(start + 1, i - start - 1);
                specials.push_back("1" + solve(inner) + "0");
                start = i + 1;
            }
        }
        sort(specials.rbegin(), specials.rend());
        string result = "";
        for (auto& i : specials) {
            result += i;
        }
        return result;
    }
    string makeLargestSpecial(string s) { return solve(s); }
};
// special string 1-> 1,0-> - 1
// checking inner string
// sort descending and adding to make lexicographically greater