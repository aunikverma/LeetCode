class Solution {
public:
    int M = 1e9 + 7;

    int t[201][201][2]; // dp

    int solve(int onesLeft, int zeroesLeft, bool lastWasOne, int& limit) {
        if (onesLeft == 0 && zeroesLeft == 0) {
            return 1;
        }

        if (t[onesLeft][zeroesLeft][lastWasOne] != -1) {
            return t[onesLeft][zeroesLeft][lastWasOne];
        }

        int result = 0;
        // explore zeroes
        if (lastWasOne) {
            for (int len = 1; len <= min(limit, zeroesLeft); len++) {
                result =
                    (result + solve(onesLeft, zeroesLeft - len, false, limit)) %
                    M;
            }
        } else {
            // explore 1
            for (int len = 1; len <= min(limit, onesLeft); len++) {
                result =
                    (result + solve(onesLeft - len, zeroesLeft, true, limit)) %
                    M;
            }
        }
        return t[onesLeft][zeroesLeft][lastWasOne] = result;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t, -1, sizeof(t));
        int startWithOne = solve(one, zero, false, limit);
        int startWithZero = solve(one, zero, true, limit);
        return (startWithOne + startWithZero) % M;
    }
};