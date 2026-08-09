class Solution {
public:
    int n;
    int t[2][101][101];

    int solveForAlice(int i, int turn, int M, vector<int>& piles) {
        if (i >= n) {
            return 0;
        }
        if (t[turn][i][M] != -1) {
            return t[turn][i][M];
        }

        int result = (turn == 1 ? -1 : INT_MAX);

        int stones = 0;
        for (int x = 1; x <= min(2 * M, n - i); x++) {
            stones += piles[i + x - 1];
            if (turn) {
                result = max(result, stones + solveForAlice(i + x, 0, max(M, x), piles));
            } else {
                result = min(result, solveForAlice(i + x, 1, max(M, x), piles));
            }
        }
        return t[turn][i][M] = result;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(t, -1, sizeof(t));
        return solveForAlice(0, 1, 1, piles);
    }
};