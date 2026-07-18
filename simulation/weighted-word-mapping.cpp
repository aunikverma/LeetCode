class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for (auto& i : words) {
            int sum = 0;
            for (char c : i) {
                sum += weights[c - 'a'];
            }
            sum %= 26;
            ans += ('a' + (25 - sum));
        }
        return ans;
    }
};