class Solution {
public:
    int findNthDigit(int n) {
        // Find which digit range n falls into
        long long len = 9, st = 1, digits = 1;

        while (n > len * digits) {
            n -= len * digits;
            len = len * 10;
            st = st * 10;
            digits++;
        }
        // Find the number and digit
        long long num = st + (n - 1) / digits;    // The number that contains the nth digit
        int index = (n - 1) % digits; // Which digit of the number

        // Convert the number to a string and return the digit
        string numstr = to_string(num);
        return (numstr[index] - '0');
    }
};
