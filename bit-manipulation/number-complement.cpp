class Solution {
public:
    int findComplement(int n) {
        int m = n;
        int mask = 0;

        if (m == 0) {
            return 1; // because complement of 0 is 1
        }
        while (m != 0) {
            mask = (mask << 1) | 1;
            m = m >> 1;
        }

        int answer = (~n) & mask;

        return answer;
    }
};