class Solution {
private:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        if (a == b)
            return a;
        return gcd(b, a % b);
    }

public:
    string gcdOfStrings(string s1, string s2) {
        int i = s1.length(), j = s2.length();
        int r = gcd(max(i, j), min(i, j));
        return (s1+s2 == s2+s1 ? s1.substr(0,r) : "");
    }
};