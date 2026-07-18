class Solution {
public:
    bool dfs(int total, int jug1, int jug2, int jug, int target,
             vector<bool>& vis) {
        if (jug > total || jug < 0 || vis[jug] == true) return false;
        if (jug == target) return true;
        vis[jug] = true;
        bool a = dfs(total, jug1, jug2, jug + jug1, target, vis);
        bool b = dfs(total, jug1, jug2, jug - jug1, target, vis);
        bool c = dfs(total, jug1, jug2, jug + jug2, target, vis);
        bool d = dfs(total, jug1, jug2, jug - jug2, target, vis);
        return a || b || c || d;
    }
    bool canMeasureWater(int jug1Capacity, int jug2Capacity,
                         int targetCapacity) {
        int total = jug1Capacity + jug2Capacity;
        vector<bool> vis(total + 1, false);
        return dfs(total, jug1Capacity, jug2Capacity, 0, targetCapacity, vis);
    }
};