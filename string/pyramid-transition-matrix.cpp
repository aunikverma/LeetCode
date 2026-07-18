class Solution {
public:
    unordered_map<string, bool> memo;
    bool solve(string curr, unordered_map<string, vector<char>>& mp, int ind, string above) {
        if (curr.length() == 1) {
            // pyramid formed
            return true;
        }
        string key = curr + "_" + to_string(ind) + "_" + above;
        if (memo.count(key)) {
            return memo[key];
        }
        if (ind == curr.length() - 1) {
            return memo[key] = solve(above, mp, 0, ""); // now go to above level
        }
        string pair = curr.substr(ind, 2);
        if (mp.find(pair) == mp.end()) {
            return memo[key] = false; // no pair available
        }
        for (char& ch : mp[pair]) {
            above.push_back(ch);
            if (solve(curr, mp, ind + 1, above)) {
                return memo[key] = true;
            }
            above.pop_back(); // backtrack
        }
        return memo[key] = false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;
        for (auto& pattern : allowed) {
            mp[pattern.substr(0, 2)].push_back(pattern[2]); // third char
        }
        return solve(bottom, mp, 0, "");
    }
};