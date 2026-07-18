class Solution {
public:
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
        int n = t1.size();
        long long ans = 0;
        int count = 0; // count of t1
        // choosing t2 instead of t1 penalty
        vector<int> penalty;

        for (int i = 0; i < n; i++) {
            if (t1[i] >= t2[i]) {
                ans += t1[i];
                count++;
            } else {
                ans += t2[i];
                penalty.push_back(t2[i] - t1[i]);
            }
        }
        if (count >= k) // already t1 tasks
        {
            return ans;
        }
        int need = k - count; // cost to switch taks
        sort(penalty.begin(), penalty.end());
        for (int i = 0; i < need; i++) {
            ans -= penalty[i];
        }

        return ans;
    }
};