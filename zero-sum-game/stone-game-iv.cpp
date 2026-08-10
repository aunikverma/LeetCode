class Solution {
public:
    bool winnerSquareGame(int n) {
        int sq = sqrt(n);
        return (sq * sq == n);
    }
};