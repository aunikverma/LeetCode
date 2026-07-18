class Solution {
public:
    int solve(vector<int>& task1, vector<int>& task1D, vector<int>& task2,
              vector<int>& task2D) {
        // minimum for task one
        int ans = INT_MAX;
        int time = INT_MAX;
        for (int i = 0; i < task1.size(); i++) {
            time = min(time, task1[i] + task1D[i]);
        }
        // now i finish task1 at minimum then second
        for (int j = 0; j < task2.size(); j++) {
            ans = min(ans, max(time, task2[j]) + task2D[j]);
        }
        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int f_land =
            solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int f_water =
            solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(f_land, f_water);
    }
};