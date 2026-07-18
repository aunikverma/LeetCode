class Solution {
public:
    int countCollisions(string directions) {
        int i = 0, j = directions.length() - 1;
        while (i < directions.length() && directions[i] == 'L') {
            i++;
        }
        while (j >= 0 && directions[j] == 'R') {
            j--;
        }
        int count = 0;
        while (i <= j) {
            if (directions[i] == 'L' || directions[i] == 'R') {
                count++;
            }
            i++;
        }
        return count;
    }
};
// skip consecutive left cars from left and right cars from right,since they'll
// never collide
