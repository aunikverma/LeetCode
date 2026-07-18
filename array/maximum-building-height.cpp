class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        int size = restrictions.size() + 1;
        // normalize the restrictions
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());
        if (restrictions[size - 1][0] != n) {
            restrictions.push_back({n, n - 1});
        }
        size = restrictions.size();

        // forward pass
        for (int i = 1; i < size; i++) {
            int m = restrictions[i][1], m_prev = restrictions[i - 1][1];
            int id = restrictions[i][0], id_prev = restrictions[i - 1][0];
            // max_slope
            int max_height = min(m, m_prev + id - id_prev);
            restrictions[i][1] = max_height;
        }

        // backward pass
        for (int i = size - 2; i >= 0; i--) {
            int m = restrictions[i][1], m_next = restrictions[i + 1][1];
            int id = restrictions[i][0], id_next = restrictions[i + 1][0];
            // max_descend
            int max_height = min(m, m_next + id_next - id);
            restrictions[i][1] = max_height;
        }

        int ans = 0;
        // maximum between two restrictions points
        for (int i = 0; i < size - 1; i++) {
            int m = restrictions[i][1], m_next = restrictions[i + 1][1];
            int id = restrictions[i][0], id_next = restrictions[i + 1][0];

            int height = (m + m_next + (id_next - id)) / 2;
            ans = max(ans, height);
        }

        return ans;
    }
};