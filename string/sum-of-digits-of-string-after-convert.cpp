class Solution {
private:
    int digitsum(int n) {
        int s = 0;
        while (n > 0) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }

public:
    int getLucky(string s, int k) {
        --k;
        string a = "";
        int n = 0;
        for (char c : s) {
            a += to_string(c - 'a' + 1); // converted into string
        }
        for (char c : a) {
            n += (c - '0'); // converted into number
        }
        while (k > 0) {
            n = digitsum(n);
            k--;
        }
        return n;
    }
};