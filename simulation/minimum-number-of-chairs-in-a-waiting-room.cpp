class Solution {
public:
    int minimumChairs(string s) {
        int ans = -1;
        int count = 0;
        for (char c : s) {
            if (c == 'E') {
                count += 1;
            } else {
                count -= 1;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};