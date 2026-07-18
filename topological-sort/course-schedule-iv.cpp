class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p,vector<vector<int>>& q) {
        vector<vector<bool>> isPreq(n, vector<bool>(n, false));
        for (auto& i : p) {
            isPreq[i[0]][i[1]] = true;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (isPreq[i][k] && isPreq[k][j]) {
                        isPreq[i][j] = true;
                    }
                }
            }
        }
        vector<bool> ans;
        for (auto& i : q) {
            if (isPreq[i[0]][i[1]]) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};