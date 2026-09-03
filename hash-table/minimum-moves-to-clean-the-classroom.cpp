class Solution {
public:
    using VB = vector<bool>;
    using VVB = vector<VB>;
    using VVVB = vector<VVB>;
    using VVVVB = vector<VVVB>;
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    struct State {
        int row;
        int col;
        int energyLeft;
        int collectedMask;
    };

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int maxEnergy = energy;

        int litterBit[20][20];
        int litterCount = 0;
        int strow = 0, stcol = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                litterBit[i][j] = -1;
                if (classroom[i][j] == 'S') {
                    strow = i;
                    stcol = j;
                } else if (classroom[i][j] == 'L') {
                    litterBit[i][j] = litterCount;
                    litterCount++;
                }
            }
        }

        // 2 ^ litterCount - 1
        int allCollected = (1 << litterCount) - 1;

        if (litterCount == 0) {
            return 0;
        }

        VVVVB visited(m,
                      VVVB(n, VVB(maxEnergy + 1, VB(1 << litterCount, false))));

        queue<State> q;
        q.push({strow, stcol, maxEnergy, 0});
        visited[strow][stcol][maxEnergy][0] = true;

        int moves = 0;
        while (!q.empty()) {
            int currSize = q.size();

            while (currSize--) {
                State curr = q.front();
                q.pop();

                if (curr.collectedMask == allCollected) {
                    return moves;
                }

                if (curr.energyLeft == 0) {
                    continue;
                }

                for (auto& d : dir) {
                    int ntrow = curr.row + d[0];
                    int ntcol = curr.col + d[1];

                    if (ntrow < 0 || ntrow >= m || ntcol < 0 || ntcol >= n) {
                        continue;
                    }
                    char cell = classroom[ntrow][ntcol];
                    if (cell == 'X') {
                        continue;
                    }
                    int ntEnergy = curr.energyLeft - 1;
                    int nextCollectedMask = curr.collectedMask;
                    if (cell == 'R') {
                        ntEnergy = maxEnergy;
                    } else if (cell == 'L') {
                        // set to 1
                        nextCollectedMask |= (1 << litterBit[ntrow][ntcol]);
                    }

                    if (!visited[ntrow][ntcol][ntEnergy][nextCollectedMask]) {
                        visited[ntrow][ntcol][ntEnergy][nextCollectedMask] =
                            true;
                        q.push({ntrow, ntcol, ntEnergy, nextCollectedMask});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};