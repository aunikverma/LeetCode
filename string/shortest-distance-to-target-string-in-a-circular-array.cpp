class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        if (words[startIndex] == target) {
            return 0;
        }
        int ans = INT_MAX;
        int count = 1, n = words.size();
        for (int i = startIndex + 1; i != startIndex; i = (i + 1) % n) {
            if (words[i] == target) {
                ans = min(ans, count);
            }
            count++;
        }
        count = 1;
        for (int i = (startIndex - 1 + n) % n; i != startIndex; i = (i - 1 + n) % n) {
            if (words[i] == target) {
                ans = min(ans, count);
            }
            count++;
        }
        return (ans != INT_MAX ? ans : -1);
    }
};