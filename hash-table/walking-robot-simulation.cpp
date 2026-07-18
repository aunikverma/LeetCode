class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;
        for (vector<int>& o : obstacles) {
            string key = to_string(o[0]) + "_" + to_string(o[1]);
            st.insert(key);
        }
        int x = 0, y = 0;
        int maxi = 0; // max distance
        pair<int, int> dir = {0, 1};
        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == -2) {
                // left 90
                dir = {-dir.second, dir.first};
            } else if (commands[i] == -1) {
                // right 90
                dir = {dir.second, -dir.first};
            } else {
                // move to dir step by step
                for (int step = 0; step < commands[i]; step++) {
                    int new_x = x + dir.first;
                    int new_y = y + dir.second;

                    string key = to_string(new_x) + "_" + to_string(new_y);
                    if (st.find(key) != st.end()) {
                        break;
                    }
                    x = new_x;
                    y = new_y;
                }
            }
            maxi = max(maxi, x * x + y * y);
        }
        return maxi;
    }
};