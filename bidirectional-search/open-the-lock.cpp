class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> locked(deadends.begin(), deadends.end());
        // start is in deadend
        if (locked.find("0000") != locked.end()) {
            return -1;
        }
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        while (!q.empty()) {
            auto [pattern, turn] = q.front();
            q.pop();
            if (pattern == target) {
                return turn;
            }
            for (int i = 0; i < 4; i++) {
                string new_pattern = pattern;
                // first +1
                new_pattern[i] =
                    char(((new_pattern[i] - '0' + 1 + 10) % 10) + '0');
                if (locked.find(new_pattern) == locked.end()) {
                    q.push({new_pattern, turn + 1});
                    locked.insert(new_pattern);
                }
                // second -1
                new_pattern = pattern;
                new_pattern[i] =
                    char(((new_pattern[i] - '0' - 1 + 10) % 10) + '0');
                if (locked.find(new_pattern) == locked.end()) {
                    q.push({new_pattern, turn + 1});
                    locked.insert(new_pattern);
                }
            }
        }
        return -1;
    }
};
