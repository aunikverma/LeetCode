class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        int a = (c1[0] + c1[1]) % 2;
        int b = (c2[0] + c2[1]) % 2; return (a == b);
    }
};