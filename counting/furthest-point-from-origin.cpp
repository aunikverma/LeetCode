class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0, right = 0, space = 0;
        for (char c : moves) {
            left += (c == 'L' ? -1 : 0);
            right += (c == 'R' ? 1 : 0);
            space += (c == '_' ? 1 : 0);
        }
        int move1 = abs((left + right) - space); // either left farthest
        int move2 = abs((left + right) + space); // right farthest
        return max(move1, move2);
    }
};