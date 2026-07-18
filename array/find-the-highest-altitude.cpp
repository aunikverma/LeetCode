class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, curr_altitude = 0;
        for (int i : gain) {
            curr_altitude += i;
            ans = max(ans, curr_altitude);
        }
        return ans;
    }
};