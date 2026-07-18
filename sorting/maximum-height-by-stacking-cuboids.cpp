class Solution {
public:
    bool Check(vector<int>& curr, vector<int>& next) {
        return (curr[0] >= next[0] && curr[1] >= next[1] && curr[2] >= next[2]);
    }
    int solveTabSpace(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int prev = i - 1; prev >= -1; prev--) {
                int not_take = next[prev + 1];
                int take = 0;
                if (prev == -1 || Check(cuboids[i], cuboids[prev])) {
                    take = cuboids[i][2] + next[i + 1];
                }
                curr[prev + 1] = max(take, not_take);
            }
            next = curr;
        }
        return curr[0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto& i : cuboids) {
            sort(i.begin(), i.end());
        }
        sort(cuboids.begin(), cuboids.end());
        // using lis logic
        return solveTabSpace(cuboids);
    }
};
