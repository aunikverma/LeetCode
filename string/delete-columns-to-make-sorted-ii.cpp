class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        vector<bool> already_sort(strs.size(), false);
        for (int c = 0; c < strs[0].size(); c++) {
            bool v = false; // deleted or not
            for (int r = 0; r < strs.size() - 1; r++) {
                if (!already_sort[r] && strs[r][c] > strs[r + 1][c]) {
                    count++;
                    v = true;
                    break;
                }
            }
            if (v) {
                continue;
            }
            for (int i = 0; i < strs.size() - 1; i++) {
                already_sort[i] = already_sort[i] | strs[i][c] < strs[i + 1][c];
            }
        }
        return count;
    }
};